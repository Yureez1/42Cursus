# User Documentation - Inception

*This guide explains how to interact with and manage the jbanchon.42.fr stack.*

---

## 📋 Services Provided
This infrastructure provides a secure WordPress environment:
* **NGINX**: Entry point handling HTTPS (Port 443).
* **WordPress**: Website engine (PHP-FPM).
* **MariaDB**: Secure database storage.

---

## 🚀 Management Commands
All actions are performed via the `Makefile` at the root:
* **Start**: `make`
* **Stop**: `make down`
* **Reset (Data Wipe)**: `make fclean`

---

## 🌐 Access
* **Website**: [https://jbanchon.42.fr](https://jbanchon.42.fr)
* **Admin Panel**: [https://jbanchon.42.fr/wp-admin](https://jbanchon.42.fr/wp-admin)

> [!WARNING]  
> Proceed through the "Connection not private" browser warning (due to self-signed SSL).

---

## 🔑 Credentials Management
* **Environment variables and credentials**: Located in `srcs/.env`.
* **Local private notes (optional)**: Keep personal copies in `secrets/` (root folder), which is git-ignored.

---

## ✅ Health Check
To verify that the services are running correctly:
1. Run `docker ps` to ensure all 3 containers are "Up".
2. Run `docker logs <container_name>` to check for internal errors.
3. Access the URL: a `200 OK` status in the browser confirms success.