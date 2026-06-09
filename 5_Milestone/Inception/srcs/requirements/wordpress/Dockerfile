FROM debian:bullseye

RUN apt-get update && apt-get upgrade -y && apt-get install -y \
    wget \
    php7.4 \
    php7.4-fpm \
    php7.4-mysql \
    mariadb-client \
    && rm -rf /var/lib/apt/lists/*

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp

COPY conf/www.conf /etc/php/7.4/fpm/pool.d/www.conf

RUN mkdir -p /var/www/wordpress && \
    chown -R www-data:www-data /var/www/wordpress

COPY tools/wp-script.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/wp-script.sh

WORKDIR /var/www/wordpress

EXPOSE 9000

ENTRYPOINT ["wp-script.sh"]