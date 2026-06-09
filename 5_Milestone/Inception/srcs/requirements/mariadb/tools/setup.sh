#!/bin/bash
set -e

SOCKET_PATH="/run/mysqld/mysqld.sock"

mysql_exec() {
    mariadb --protocol=socket --socket="${SOCKET_PATH}" -uroot -e "$1" 2>/dev/null \
    || mariadb --protocol=socket --socket="${SOCKET_PATH}" -uroot -p"${SQL_ROOT_PASSWORD}" -e "$1"
}

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql
fi

mysqld_safe --datadir=/var/lib/mysql --skip-networking --socket="${SOCKET_PATH}" &

until mariadb-admin --protocol=socket --socket="${SOCKET_PATH}" ping --silent >/dev/null 2>&1; do
    echo "Waiting for MariaDB..."
    sleep 2
done

mysql_exec "CREATE DATABASE IF NOT EXISTS \`${SQL_DATABASE}\`;"
mysql_exec "CREATE USER IF NOT EXISTS \`${SQL_USER}\`@'%' IDENTIFIED BY '${SQL_PASSWORD}';"
mysql_exec "GRANT ALL PRIVILEGES ON \`${SQL_DATABASE}\`.* TO \`${SQL_USER}\`@'%';"
mysql_exec "ALTER USER 'root'@'localhost' IDENTIFIED BY '${SQL_ROOT_PASSWORD}';"
mysql_exec "FLUSH PRIVILEGES;"

mariadb-admin --protocol=socket --socket="${SOCKET_PATH}" -uroot -p"${SQL_ROOT_PASSWORD}" shutdown

echo "Mariadb is starting..."
exec mariadbd --user=mysql --datadir=/var/lib/mysql