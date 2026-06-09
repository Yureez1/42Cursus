*This project has been created as part of the 42 curriculum by jbanchon.*

## Description
The **Inception** project is a major step in the 42 curriculum designed to introduce students to system administration through Docker. The core objective is to manually build a small infrastructure of different services, each running in its own container, using **Docker Compose**. 

The infrastructure consists of three mandatory services:
- **NGINX**: Acts as the entry point, handling TLS v1.2/v1.3.
- **WordPress + PHP-FPM**: The content management system.
- **MariaDB**: The relational database.

A key constraint of this project is that every image must be built from a custom `Dockerfile` based on **Debian Bullseye/Buster**. Pre-made images from Docker Hub are strictly forbidden.

---

## Project Description

### Main Design Choices
The project is built on the principle of **service isolation**. 
- **NGINX** is the only container with an open port to the host (Port 443), ensuring all incoming traffic is encrypted. 
- **PHP-FPM** is used instead of the standard Apache/PHP module to allow better separation between the web server and the application logic. 
- **Scripts (Entrypoints)** use the `exec` command to ensure the main service (like `mariadbd` or `php-fpm`) runs as **PID 1**, allowing Docker to manage service lifecycles properly.

### Technical Comparisons

| Feature | Choice A | Choice B | Comparison for Inception |
| :--- | :--- | :--- | :--- |
| **VM vs Docker** | **Virtual Machines** | **Docker** | Docker shares the host OS kernel, making it much more lightweight and faster than a VM, which requires a full guest OS and hypervisor. |
| **Secrets vs Env Vars** | **Docker Secrets** | **Env Variables** | This project currently uses environment variables from `srcs/.env` for simplicity. Docker Secrets would be the stronger option for production credentials. |
| **Docker vs Host Net** | **Docker Network** | **Host Network** | Docker Network provides a private bridge. It allows services to talk to each other (e.g., WP to DB) while being invisible to the outside world. |
| **Volumes vs Bind Mounts** | **Docker Volumes** | **Bind Mounts** | Docker Volumes are managed by Docker for better portability, while Bind Mounts (used here) link a specific host path to a container path for persistent data. |

---

## Instructions

### Prerequisites
- A **Debian** or **Ubuntu** environment.
- **Docker** and **Docker Compose** installed.
- **Sudo** privileges to modify `/etc/hosts`.

### Installation and Execution
1.  **Configure the Domain**:
    Add the following line to your `/etc/hosts` file:
    ```bash
    echo "127.0.0.1 jbanchon.42.fr" | sudo tee -a /etc/hosts
    ```

2.  **Build and Start**:
    Run the Makefile at the root of the project to automate the setup:
    ```bash
    make
    ```
    This will create the necessary data directories (`/home/jbanchon/data/`), build the images, and start the containers.

3.  **Configure credentials**:
    Edit `srcs/.env` before running in your own environment and replace default passwords.

4.  **Access the site**:
    Open your browser and navigate to: `https://jbanchon.42.fr`

### Makefile Rules
- `make`: Sets up the volumes and starts the infrastructure.
- `make down`: Stops all services.
- `make fclean`: Stops services and removes all images, volumes, and local data.
- `make re`: Performs an `fclean` followed by a fresh `make`.

---

## Resources

### Documentation and References
- [Official Docker Documentation](https://docs.docker.com/)
- [Nginx Configuration Guide](https://nginx.org/en/docs/)
- [MariaDB Knowledge Base](https://mariadb.com/kb/en/)
- [Inception Tutorial - Grademe](https://tuto.grademe.fr/inception/)
- [Inception VM Guide - Bakr-1](https://github.com/Bakr-1/inceptionVm-guide)

### AI Usage Disclosure
This project utilized **Gemini 3 Flash** as a technical collaborator. AI was used for the following specific tasks:
- **Configuration Debugging**: Identifying syntax errors in the PHP-FPM `www.conf` file (specifically the comment character issue).
- **Process Management**: Understanding and implementing the `exec` command in shell scripts to ensure services run as PID 1, avoiding "hacks" like `tail -f`.
- **Infrastructure Architecture**: Clarifying the communication flow between NGINX, FastCGI, and MariaDB.
- **Documentation**: Assisting in the translation and professional formatting of this README file.