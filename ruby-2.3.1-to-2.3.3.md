## Atualizado ruby 2.3.1 para 2.3.3 em produção.

1. Deixe o projeto em desenvolvimento funcionando, copiando o gemfile e gemfile.lock do skeleton_md_rails, com os seguintes passos:

      1. Verifique no gemset as gems anteriores com as novas e coloque as que estão faltando no novo gemset.
      1. Verifique no novo gemset se há alguma gem que não está sendo usada no novo e retire-a.
      1. Vá em `config/environments/production.rb` e verifique se a linha contendo `config.assets.js_compressor` recebe `Uglifier.new(harmony: true)` ficando `config.assets.js_compressor = Uglifier.new(harmony: true)` caso contrario altere-a.
      1. Mude a versão do ruby em `confi/deploy.rb`
      1. Verifique se o RailsAdmin em `config/initializers/rails_admin.rb` a configuração do cancancan está como `config.authorize_with :cancancan`. Caso esteja só com 2 `:cancan`, irá ficar com um erro, então adicione mais um ficando `:cancancan`.
      1. Verifique se o tema está correto com a **sidebar** funcionando corretamente. Caso contrario entre no [GitHub do tema](https://github.com/thefalked/rails_admin_theme) e adicione o `javascript` como descrito no README. Também retire o gravatar. (não gere os comando para a criação dos **assets**)
      1. Inicialize o projeto na sua maquina e veja se está tudo funcionando.

1. Conecte-se ao servidor pelo ssh, faça login no usuário com o comando `sudo su nome_do_usuario`.

1. Instale o ruby pelo rvm `cd && rvm install 2.3.3`.

1. Logue no shell usando `/bin/bash --login`.

1. Defina como default `rvm use 2.3.3 --default`.

1. Saia do bash `exit` e volte para o usuário com sudo `exit`.

1. Vá para o nginx e mude somente a versão no arquivo em `cd /etc/nginx/sites-enabled/` (APP3) ou `cd /opt/nginx/sites-available` (APP1).

1. Restarte o NGINX `sudo service nginx restart`.

1. Faça o deploy com `mina production deploy`.

> (Em caso de erros vá ao final do arquivo de [steps](/steps.md) e verifique os logs de erro)
