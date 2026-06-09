#!/bin/bash
set -e

until mysqladmin -h mariadb -u ${SQL_USER} -p${SQL_PASSWORD} ping; do
    echo "Waiting for MariaDB..."
    sleep 2
done

cd /var/www/wordpress

if [ ! -f "wp-config.php" ]; then

    wp core download --allow-root

    wp config create --allow-root \
        --dbname=${SQL_DATABASE} \
        --dbuser=${SQL_USER} \
        --dbpass=${SQL_PASSWORD} \
        --dbhost=mariadb:3306 \

    wp core install --allow-root \
        --url=$DOMAIN_NAME \
        --title=$WP_TITLE \
        --admin_user=$WP_ADMIN_USER \
        --admin_password=$WP_ADMIN_PASSWORD \
        --admin_email=$WP_ADMIN_EMAIL \
    
    wp user create --allow-root \
        $WP_USER $WP_EMAIL \
        --user_pass=$WP_PASSWORD \
        --role=author
fi

mkdir -p /run/php

echo "WordPress started on port 9000"
exec php-fpm7.4 -F