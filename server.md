# Creating a New Server

###### First create a new user and add him to the sudoers

```bash
adduser agenciaw3
```

Set the `password` and press `enter` to use the default value and them type `Y`


Now you have to set the user created has a sudoer

```bash
usermod -aG sudo agenciaw3
```

###### Desabling root user

Why would you delete the root password?

Deleting the root user is a security precaution and overall just something that is good to do.

to disable use:
```bash
su - agenciaw3
sudo passwd -l root
```

###### Updating Server

Use the follow commands:

```bash
sudo apt-get update && sudo apt-get upgrade -y && sudo apt-get autoremove && sudo apt-get full-upgrade
```

###### Installing Necessary packages

```bash
sudo apt-get install imagemagick libpq-dev -y
```

###### Installing NGINX & Passenger

We'll add their repository and then install and configure their packages.

```bash
sudo apt-key adv --keyserver hkp://keyserver.ubuntu.com:80 --recv-keys 561F9B9CAC40B2F7 && sudo sh -c 'echo deb https://oss-binaries.phusionpassenger.com/apt/passenger focal main > /etc/apt/sources.list.d/passenger.list' && sudo apt-get update && sudo apt-get install -y nginx-extras libnginx-mod-http-passenger && if [ ! -f /etc/nginx/modules-enabled/50-mod-http-passenger.conf ]; then sudo ln -s /usr/share/nginx/modules-available/mod-http-passenger.load /etc/nginx/modules-enabled/50-mod-http-passenger.conf ; fi && sudo ls /etc/nginx/conf.d/mod-http-passenger.conf
```

Configuring the NGINX with Passenger.

```bash
sudo nano /etc/nginx/conf.d/mod-http-passenger.conf
```

And paste:

```bash
passenger_root /usr/lib/ruby/vendor_ruby/phusion_passenger/locations.ini;
```

Save the file and restart the NGINX

```bash
sudo service nginx restart
```

###### Installing Certbot for SSL

First install the packages

```bash
sudo snap install core; sudo snap refresh core && sudo apt-get remove certbot && sudo snap install --classic certbot && sudo ln -s /snap/bin/certbot /usr/bin/certbot
```

Let’s Encrypt certificates expire after 90 days. We encourage you to renew your certificates automatically. Here we add a cron job to an existing crontab file to do this.

```bash
crontab -e
```

Add the certbot command to run daily. In this example, we run the command every day at noon. The command checks to see if the certificate on the server will expire within the next 30 days, and renews it if so. The --quiet directive tells certbot not to generate output.

```bash
0 12 * * * /usr/bin/certbot renew --quiet
```

Save and close the file. All installed certificates will be automatically renewed and reloaded.

Now create the file `options-ssl-nginx.conf`

```bash
sudo nano /etc/nginx/options-ssl-nginx.conf
```

Inside paste:

```bash
# This file contains important security parameters. If you modify this file
# manually, Certbot will be unable to automatically provide future security
# updates. Instead, Certbot will print and log an error message with a path to
# the up-to-date file that you will need to refer to when manually updating
# this file.

ssl_session_cache shared:le_nginx_SSL:1m;
ssl_session_timeout 1440m;

ssl_protocols TLSv1 TLSv1.1 TLSv1.2;
ssl_prefer_server_ciphers on;

ssl_ciphers "ECDHE-ECDSA-CHACHA20-POLY1305:ECDHE-RSA-CHACHA20-POLY1305:ECDHE-ECDSA-AES128-GCM-SHA256:ECDHE-RSA-AES128-GCM-SHA256:ECDHE-ECDSA-AES256-GCM-SHA384:ECDHE-RSA-AES256-GCM-SHA384:DHE-RSA-AES128-GCM-SHA256:DHE-RSA-AES256-GCM-SHA384:ECDHE-ECDSA-AES128-SHA256:ECDHE-RSA-AES128-SHA256:ECDHE-ECDSA-AES128-SHA:ECDHE-RSA-AES256-SHA384:ECDHE-RSA-AES128-SHA:ECDHE-ECDSA-AES256-SHA384:ECDHE-ECDSA-AES256-SHA:ECDHE-RSA-AES256-SHA:DHE-RSA-AES128-SHA256:DHE-RSA-AES128-SHA:DHE-RSA-AES256-SHA256:DHE-RSA-AES256-SHA:ECDHE-ECDSA-DES-CBC3-SHA:ECDHE-RSA-DES-CBC3-SHA:EDH-RSA-DES-CBC3-SHA:AES128-GCM-SHA256:AES256-GCM-SHA384:AES128-SHA256:AES256-SHA256:AES128-SHA:AES256-SHA:DES-CBC3-SHA:!DSS";
```

###### Installing RVM

```bash
gpg --keyserver hkp://pool.sks-keyservers.net --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3 7D2BAF1CF37B13E2069D6956105BD0E739499BDB &&
\curl -sSL https://get.rvm.io | bash -s stable --rails
```

###### Configuring the PostgreSQL Database

Go to the PostgreSQL server and go to the directory `/etc/postgresql/9.3/main` and open the file `pg_hba.conf`

```bash
nano /etc/postgresql/9.3/main/pg_hba.conf
```

At the end of the file write a **new line** with the server **IP**: (use `tab` for the spaces)(Change the **0.0.0.0**/24 for the new server ip)

```bash
host  all   all   0.0.0.0/24   md5
```

Go to the `w3case` user and restart the postgres
