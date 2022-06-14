# Configuração Servidor Passo a Passo

[‹ Voltar para documentações](/readme.md)

Passo a passo para configurar um usuário no servidor de **production**.

- [1. Criando um usuário](#markdown-header-1-criando-um-usuario)
- [2. Criando banco de dados](#markdown-header-2-criando-banco-de-dados)
- [3. Configurado Storage](#markdown-header-3-configurado-storage)
- [4. Configurando projeto](#markdown-header-4-configurando-projeto)
- [5. Colocar SSL (HTTPS)](#markdown-header-5-colocar-ssl-https)
- [6. Comando úteis](#comando-uteis)

## 1. Adicionar chave ssh no servidor de staging ou production

```bash
# Adicionar chave ssh no servidor
ssh-copy-id agenciaw3@app3.agenciaw3.digital
ssh-copy-id postgres@db.w3case.net.br
ssh-copy-id agenciaw3@storage.agenciaw3.digital
```

## 1. Criando um usuário

```bash
# Acesso SSH
ssh agenciaw3@app3.agenciaw3.digital

# Listar diretórios
ls /home

# Adicionar usuário
sudo adduser nome_do_usuario

# Trocar para o usuário criado
sudo su nome_do_usuario

# Ir para pasta root do usuário
cd

# Criar Arquivo com o nome shell.sh
nano shell.sh

# Colar o codigo do Shell

#!/bin/bash
echo $1
curl -o- https://raw.githubusercontent.com/nvm-sh/nvm/v0.37.2/install.sh | bash &&
echo 'export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"' >> .profile &&
export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && \. "$NVM_DIR/nvm.sh"
[ -s "$NVM_DIR/bash_completion" ] && \. "$NVM_DIR/bash_completion"
nvm install --lts &&
npm install --global yarn &&
gpg --keyserver hkp://pgp.mit.edu --recv-keys 409B6B1796C275462A1703113804BB82D39DC0E3 7D2BAF1CF37B13E2069D6956105BD0E739499BDB &&
\curl -sSL https://get.rvm.io | bash &&
source ~/.rvm/scripts/rvm &&
rvm requirements &&
rvm install $1 &&
rvm use $1 --default &&
rvm rubygems current &&
rvm @global do gem install bundle &&
ssh-keygen &&
cat ~/.ssh/id_rsa.pub

# Dar permissão para rodar
chmod 777 shell.sh

# Executar o arquivo (lembrar de passar a versão na frente do nome do arquivo)
# De enter em todas as opções que aparecer enquanto o script está executando
#./shell.sh 3.0.1

# Colocoar chave publica no repositório do bitbutcket
Repository settings -> Access keys

# Exclua o arquivo
rm shell.sh

# Sair do usuário
exit

# Acessar lista arquivos de domínios
cd /etc/nginx/sites-enabled/

# Criar arquivo com sudo do local e adicionar o codigo abaixo
sudo nano nomedosite.com.br

# Adicionar este código e colocar o nomedosite, nomedouser e a versão do ruby
server {
  listen 80;
  access_log off;

  server_name
    nomedosite.com.br
    www.nomedosite.com.br;

  root /home/nomedouser/public_html/railsapp/current/public;

  passenger_enabled on;
  passenger_app_env production;

  location /cable {
    passenger_app_group_name myapp_websocket;
    passenger_force_max_concurrent_requests_per_process 0;
  }

  passenger_ruby /home/nomedouser/.rvm/gems/ruby-X.X.X/wrappers/ruby;

  # Allow uploads up to 100MB in size
  client_max_body_size 100m;

  location ~ ^/(assets|packs) {
    expires max;
    gzip_static on;
  }

  #listen 443 ssl;
  #ssl_certificate /etc/letsencrypt/live/nomedosite.com.br/fullchain.pem;
  #ssl_certificate_key /etc/letsencrypt/live/nomedosite.com.br/privkey.pem;
  #include /etc/nginx/options-ssl-nginx.conf;

  #if ($scheme != "https") {
  #  return 301 https://$host$request_uri;
  #}
}

# Reiniciar NGINX
sudo service nginx restart
```

# 2. Criando banco de dados

```bash
# Acessar banco
ssh postgres@db.w3case.net.br

# Criar usuario no postgres
createuser nome_do_usuario

# Criar o banco de dados
createdb nome_do_usuario

# Trocar a senha do usuário
psql -c "alter user nome_do_usuario with password 'senha'"

# Sair da conexão
exit
```

# 3. Configurado Storage

```bash
# Acessar Storage
ssh agenciaw3@storage.agenciaw3.digital

# Criar usuário do storage
sudo adduser nome_do_usuario

# Ir para o usuário
sudo su nome_do_usuario

# Ir para pasta do usuário
cd

# Criar pastas
mkdir public_html &&
mkdir public_html/railsapp/

# Se o seed não tiver imagem
mkdir public_html &&
mkdir public_html/railsapp/ &&
mkdir public_html/railsapp/storage

# Sair do usuário
exit

# Adicionar site no NGIX
cd /etc/nginx/sites-available/

# Criar arquivo com sudo e adicionar o códgio abaixo
sudo nano nomedosite.com.br

# Adicionar o código no arquivo criado acima
server {
  listen 80;
  server_name
    cdn1.nomedosite.com.br;
  root /home/nomedosite/public_html/railsapp/storage;

  #listen 443 ssl;

  #ssl_certificate /etc/letsencrypt/live/cdn1.nomedosite.com.br/fullchain.pem;
  #ssl_certificate_key /etc/letsencrypt/live/cdn1.nomedosite.com.br/privkey.pem;
  #include /etc/letsencrypt/options-ssl-nginx.conf;
}

# Reiniciar NGINX
sudo service nginx restart
```

# 4. Configurando projeto

```bash
# Ir no projeto e alterar o arquivo deploy na pasta config do projeto
# Colocar a versão do ruby
# Ex: set :ruby_version, '2.3.3'
set :ruby_version, 'versaoaqui'

# Adicionar repositório do projeto
# colocar o mesmo link utilizado no git clone
set :repository, ''

# Server Production
task :production do
  set :rails_env, 'production'
  set :user, 'nomedousuario_do_servidor_abaixo'
  set :domain, 'servidoraqui'
  set :deploy_to, '/home/nomedousuario/public_html/railsapp'
  set :branch, 'deploy'
end

# Criar branch deploy, subir no git e fazer o setup do projeto no servidor
git checkout -b deploy && git push origin deploy && mina production setup

# Acessar a aplicação
ssh agenciaw3@app3.agenciaw3.digital

# Acessar usuario
sudo su nome_do_usuario

# Acessar os arquivos de configurações e editar os arquivos applicaton.yml, database.yml e secret.yml
cd ~/public_html/railsapp/shared/config/

# ARQUIVO DO APPLICATION
# Configuration all env mail
SMTP_ADDRESS: 'smtp.agenciaw3.digital'
SMTP_PORT: '587'
SMTP_DOMAIN: 'agenciaw3.digital'
SMTP_USER_NAME: 'no-replay@agenciaw3.digital'
SMTP_PASSWORD: ''

# From email
SMTP_FROM_MAIL: ''

# Paths and URls
UPLOAD_HOST: 'https://cdn1.nomedosite.com.br/'
SFTP_FOLDER: 'public_html/railsapp/storage/'
SFTP_HOST: 'cdn1.nomedosite.com.br'
SFTP_USER: ''
SFTP_PASSWORD: ''

RACK_MULTIPART_PART_LIMIT: "0"
RACK_MULTIPART_LIMIT: "0"

RECAPTCHA_SITE_KEY: ""
RECAPTCHA_SECRET_KEY: ""

DOMAIN: ""

# ARQUIVO DO DATABASE
production:
  host: db.w3case.net.br
  adapter: postgresql
  encoding: unicode
  database: nomeaqui
  pool: 5
  username: nomeaqui
  password: senhaaqui

# Gerar secret (terminal normal)
rake secret

# ARQUIVO DO SECRET
production:
  secret_key_base: secretaq

# Sair do usuario
exit

# Reiniciar NGINX
sudo service nginx restart

# Saia do ssh e de o deploy do projeto
mina production deploy

# Fazer o seed caso tenha
mina production "rake[db:seed]"
```

# 5. Colocar SSL (HTTPS)

```bash
# Acessar o servidor
ssh agenciaw3@app3.agenciaw3.digital

# LetsEncrypt
sudo certbot --nginx -d example.com -d www.example.com
# ou
sudo certbot certonly --webroot --agree-tos -w /home/skeleton/public_html/railsapp/current/public -d www.nomedosite.com.br -d nomedosite.com.br

# Remover comentarios de SSL do arquivo
sudo nano /etc/nginx/sites-enabled/nomedosite.com.br

# Reiniciar NGINX
sudo service nginx restart

# Sair e ir para o storage
ssh agenciaw3@storage.agenciaw3.digital

# Gerar o letsencrypt
sudo letsencrypt certonly -a webroot --webroot-path=/home/nomedousuario/public_html/railsapp/storage -d cdn1.nomedosite.com.br

# Remover os comentarios em
sudo nano /etc/nginx/sites-available/www.nomedosite.com.br

# Reiniciar NGINX
sudo service nginx restart

# Sair
exit
```

# Comando úteis

```bash
# Rollback da aplicação para a ultima versão no ar
# OBS: Não funciona no banco de dados
mina production rollback

# Abre o console em produção
mina production console

# Abre o log de erros do servidor
mina production log

# Abre uma sessão ssh no servidor e vai para a pasta de deploy (public_html/railsapp)
mina production ssh

# Limpar versões antigas do projeto
mina production deploy:cleanup

# Rodar qualquer comando bash
mina production "run[ls -a]"

# Roda comandos rails exemplo:
mina production "rails[console]"

# Roda comandos rake exemplo:
mina production "rake[db:migrate]"

# Estas devem ser usadas somente em deploy

# Checa por alterações em `:migration_dirs` e roda `db:migrate` se necessário.
# Pode ser foraçdo com `:force_migrate`.
mina production rails:db_migrate

# Checa por alterações em `:asset_dirs` e roda `assets:precomile` se necessário.
# Pode ser forçado com `:force_asset_precompile`.
mina production rails:assets_precompile

# Roda `db:create`
mina production rails:db_create

# Roda `db:rollback`
mina production rails:db_rollback

# Roda `db:schema:load`
mina production rails:db_schema_load
```

### [Clique aqui para ir a documentação sobre mina](http://mina-deploy.github.io/mina/default_plugins.html)
