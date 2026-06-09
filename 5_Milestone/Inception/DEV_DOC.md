# Developer Documentation - Technical Implementation

*This document is intended for developers or administrators who want to understand, maintain, or modify the `jbanchon.42.fr` infrastructure.*

---

## 🏗️ Environment Setup

### Prerequisites
To set up this project on a **Debian-based** Linux system, install:
- **Docker Engine** (v20.10+)
- **Docker Compose** (v2.0+)
- **Make**
- **OpenSSL** (optional, for certificate inspection)

### Project Structure
Main paths used by the stack:
- `srcs/docker-compose.yml`: Service orchestration (build, network, volumes).
- `srcs/.env`: Runtime environment variables used by MariaDB and WordPress.
- `srcs/requirements/`: Dockerfiles, service configs, and startup scripts.
- `secrets/`: Local, git-ignored files for personal credentials (not consumed automatically by Docker Compose in the current implementation).

### Credentials Handling
Current implementation reads credentials from `srcs/.env` (`SQL_PASSWORD`, `SQL_ROOT_PASSWORD`, `WP_ADMIN_PASSWORD`, etc.).

Recommendations for local development:
1. Keep non-production/test values in `srcs/.env`.
2. Store private values in `secrets/` for your own tracking if needed.
3. Ensure sensitive files remain git-ignored.

---

## 🚀 Build and Launch

The project lifecycle is managed through the root `Makefile`.

### Initial Build
```bash
make
```

This command:
- Creates local data directories in `/home/<user>/data/`.
- Builds custom images based on Debian Bullseye.
- Creates/uses the private bridge network.
- Starts containers in detached mode.

### Rebuild After Changes
If you modify a Dockerfile or service configuration:
```bash
make all
```

If you need a full reset (deletes containers, images, volumes, and `/home/<user>/data`):
```bash
make re
```

---

## 🛠️ Container & Volume Management

Useful commands:

| Task | Command |
| --- | --- |
| Check service status | `docker ps` |
| View real-time logs | `docker compose -f srcs/docker-compose.yml logs -f` |
| Open shell in container | `docker exec -it <container_name> bash` |
| List volumes | `docker volume ls` |
| Inspect network | `docker network inspect srcs_inception` |

---

## 💾 Storage & Persistence

This project uses **bind mounts** for persistence.

### Host Data Locations
- MariaDB data: `/home/jbanchon/data/mariadb/`
- WordPress data: `/home/jbanchon/data/wordpress/`

### Persistence Behavior
Containers can be removed and recreated without losing application data, as long as the host directories above are preserved.

---

## ⚙️ Process Management (PID 1)

Entrypoint scripts use `exec` to launch the main service process:
- MariaDB: `exec mariadbd ...`
- WordPress/PHP-FPM: `exec php-fpm7.4 -F`

This ensures services run as PID 1 and receive signals correctly for graceful shutdown.

---

## 🛡️ Security Notes

- **Network isolation**: Only Nginx exposes a host port (`443`); WordPress and MariaDB are internal.
- **TLS**: Nginx is configured for `TLSv1.2` and `TLSv1.3` only.
- **Credential exposure**: Secrets are currently environment-based via `.env`; avoid using real production passwords in this repository.
