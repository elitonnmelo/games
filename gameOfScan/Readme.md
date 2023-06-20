# Jogo de Digitação

Este é um jogo de digitação simples, onde letras serão exibidas na tela e você precisa digitá-las antes que alcancem a parte inferior da janela. O jogo utiliza a biblioteca SFML para renderização gráfica.

## Pré-requisitos

Certifique-se de ter instalado os seguintes itens antes de executar o jogo:

- SFML: Execute o seguinte comando no terminal para instalar a biblioteca SFML:
    ```bash
    $ sudo apt-get install libsfml-dev
    ```

- Make: O jogo utiliza um Makefile para simplificar a compilação e execução. Certifique-se de ter o `make` instalado no seu sistema.

## Compilação e Execução

Siga as etapas abaixo para compilar e executar o jogo:

1. Navegue até o diretório do jogo no terminal.

2. Execute o seguinte comando para compilar o programa:
    ```bash
    $ make
    ```

3. Após a compilação bem-sucedida, execute o jogo com o comando:
    ```bash
    $ make run
    ```

Certifique-se de estar no diretório do jogo ao executar os comandos acima. O arquivo Makefile fornecido cuidará da compilação e execução corretas.

## Controles do Jogo

- Teclas: Digite as letras exibidas na tela antes que elas alcancem a parte inferior da janela.
- ESC: Pressione a tecla ESC para voltar ao menu principal durante o jogo ou para sair do jogo quando estiver no menu principal.

## Dificuldade do Jogo

Você pode ajustar a dificuldade do jogo no menu principal, selecionando a opção "Alterar dificuldade do jogo". Existem quatro níveis de dificuldade disponíveis:

- Fácil: Velocidade baixa e menor frequência de letras.
- Médio: Velocidade média e frequência moderada de letras.
- Difícil: Velocidade alta e frequência maior de letras.
- Muito Difícil: Velocidade muito alta e alta frequência de letras.

## Instruções do Jogo

Você pode acessar as instruções do jogo no menu principal, selecionando a opção "Instruções do jogo". As instruções fornecem uma breve descrição do objetivo do jogo e como jogá-lo.

Divirta-se jogando o Gmae of Scan!

