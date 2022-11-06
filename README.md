# Sistema de Bodega - UFFS Chapecó

Trabalho Final desenvolvido na 2º Fase em linguagem C durante curso de CC da UFFS Chapecó, utilizando conceitos de TAD, ponteiros e listas ordenadas.

| :placard: Vitrine.Dev |     |
| -------------  | --- |
| :sparkles: Nome        | **Bodega**
| :label: Tecnologias | c, tad
|  🖥  Curso     | https://cc.uffs.edu.br

## Detalhes do projeto

### O Sistema da Bodega

Você foi contratado pelo seu Joãozin da Bodega para criar um sistema com o qual ele possa controlar alguns detalhes do seu business. Seu Joãozin já definiu o que é mais importante, para que você comece a criar a estrutura do sistema para a melhor bodega do sul do país:

#### Organização do código:
**O programa deverá se chamar Bodega**
1. Crie uma estrutura Empresa que contém o nome e o CNPJ da bodega.
2. Crie outra chamada Bebida com os seguintes atributos: código, o nome da bebida, o conteúdo líquido em ml, o preço de venda e a quantidade em estoque.  A função compraBebida, que atualiza o estoque da bebida em questão, e  a vendeBebida, que valida se a bebida em questão pode ser vendida para um cliente com idade (+ de 18 anos) e, caso afirmativo, retira o número de unidades do estoque.
    2.1 Há dois tipos de bebida:
        2.1.1 Alcoólicas: possuem um atributo com o teor alcoólico e só podem ser vendidas para clientes com mais de 18 anos.
        2.1.2 Não-alcoólicas: têm venda livre.
3. A última estrutura que seu Joãozin precisa é a de clientes. Nela seu Joãzin cadastra todos seus clientes para saber quem compra na sua bodega. Os dados de clientes precisam ser o código, o nome, o CPF, idade, e um campo em que seu Joãzin informa se pode vender fiado para esse cliente ou não (por exemplo, 1 sim - 0 não).
4. Crie um menu interativo que pergunta ao usuário o que deseja fazer:
    * Cadastrar bebida;
    * Mostrar bebidas;
    * Comprar bebida;
    * Vender bebida;
    * Cadastrar cliente;
    * Mostrar clientes;
    * Sair do sistema;

* 4.1 O que acontece em cada item do menu:
    + 4.1.1 Ao escolher a Opção Cadastrar bebida: Leia os dados da bebida a ser cadastrada via teclado, na sequência atualiza a lista encadeada criada. É necessário verificar se o código da bebida já existe.
    + 4.1.2 Ao escolher a Opção Mostrar bebidas: Mostre os dados de todas as bebidas.
    + 4.1.3 Ao escolher a Opção Comprar bebida: Peça um código de bebida para compra e a quantidade de unidades a serem compradas. A função compraBebida  recebe os dados e atualiza o estoque da bebida comprada ou avisa que o código da bebida não existe na lista. 
    + 4.1.4 Ao escolher a Opção Vender bebida: Peça o CPF do cliente, um código de bebida para venda e a quantidade de unidades a serem vendidas. Deve ser chamada a função vendeBebida (passando os dados informados). Durante a venda de uma bebida é necessário verificar se a bebida está disponível no estoque. Além disso, para bebidas alcoólicas, verifique se o cliente é maior de idade. 
    + 4.1.5 Ao escolher a Opção Cadastrar cliente: Leia os dados via teclado e adicione na lista. A inserção deve ser feita na ordem da idade, ou seja, insira o cliente antes do elemento cuja a idade for maior que a do cliente sendo cadastrado.
    + 4.1.6 Ao escolher a Opção Mostrar clientes: Mostre os dados de todos os clientes.
    + 4.1.7 Ao escolher a Opção Sair do sistema: Saia do sistema e libere toda a memória apresentado quantos elementos foram liberados (somando os elementos de cada lista).  

**OBS: Considere que todos os dados alfanuméricos (strings) não serão compostos, ou seja, sem espaço. Assim, você poderá utilizar o scanf(“%s”, ).**

#### Avaliação:

* A avaliação será realizada considerando a apresentação do código e as funcionalidades implementadas.
* O trabalho pode ser realizado em dupla, porém, a avaliação considera não só o resultado final mas a participação e engajamento da equipe no desenvolvimento. Assim, os membros da dupla podem ter notas distintas.
* Códigos que não sejam corretamente identados sofrerão duras penalidades :)
* Reaproveitamento de código.
    * Criar funções reutilizáveis
* A criatividade no desenvolvimento será recompensada.
    * Por exemplo, utilizar uma BST para agilizar a busca dos dados (opcional)
    * Utilizar o conceito de TAD (.h e .c)
