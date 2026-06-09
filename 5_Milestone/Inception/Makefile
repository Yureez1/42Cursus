LOGIN = $(USER)
DATA_PATH = /home/$(LOGIN)/data

all:
	@mkdir -p $(DATA_PATH)/mariadb
	@mkdir -p $(DATA_PATH)/wordpress
	docker compose -f srcs/docker-compose.yml up --build -d

restart:
	docker compose -f srcs/docker-compose.yml restart

down:
	docker compose -f srcs/docker-compose.yml down

start:
	docker compose -f srcs/docker-compose.yml up -d

clean:
	docker compose -f srcs/docker-compose.yml down --rmi all --volumes

fclean: clean
	@docker system prune -a --volumes
	@sudo rm -rf $(DATA_PATH)

re: fclean all

.PHONY: all down clean fclean re restart start stop