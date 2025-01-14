# Gerador e Manipulador de Arquivos Criptografados em C

Este projeto foi desenvolvido como parte de uma atividade prática na disciplina de **Estrutura de Dados**, no curso universitário. O objetivo da atividade era criar um algoritmo em **C** que permitisse criptografar e descriptografar arquivos de texto, fornecendo uma forma de troca segura de informações entre colegas.

---

## Contexto

A atividade consistia em criar um sistema simples onde um arquivo de texto poderia ser criptografado e posteriormente descriptografado por um colega, garantindo que o conteúdo do arquivo fosse protegido durante a troca. O algoritmo foi desenvolvido para simular um processo básico de criptografia de texto, com o uso de funções que alteram os valores ASCII dos caracteres do conteúdo.

---

## Funcionalidades

- **Criação de Arquivos**: Gera arquivos de texto com conteúdo criptografado.
- **Edição de Arquivos**: Permite editar o conteúdo de arquivos já existentes e criptografá-los novamente.
- **Descriptografia**: Oferece a possibilidade de ler e descriptografar o conteúdo de um arquivo criptografado.
- **Nomeação Automática de Arquivos**: Geração de nomes aleatórios para os arquivos de texto, garantindo que cada arquivo tenha um identificador único.

---

## Como Funciona

O algoritmo segue o processo de criptografar o conteúdo do arquivo utilizando uma técnica simples baseada na alteração dos valores ASCII dos caracteres do texto. Duas funções de criptografia são aplicadas sequencialmente, aumentando a segurança.

### Passos:

1. **Criação de um arquivo**: O usuário pode criar um arquivo de texto com um nome aleatório e conteúdo digitado.
2. **Edição de arquivo**: Permite alterar o conteúdo de um arquivo já existente e criptografá-lo novamente.
3. **Leitura e Descriptografia**: O usuário pode ler um arquivo criptografado e descriptografar seu conteúdo.

---

## Funcionalidades Principais

1. **Criptografia**: A criptografia é feita em duas etapas para aumentar a segurança, utilizando um deslocamento no valor ASCII dos caracteres.
2. **Descriptografia**: O conteúdo criptografado é revertido utilizando o processo inverso das funções de criptografia.
3. **Interface de Comando**: O programa oferece um menu simples para interagir com o sistema de arquivos.

---

## Estrutura do Projeto

O código principal do projeto está implementado na linguagem **C**. As funções do programa incluem:

- **Criptografar/Descriptografar**: Funções `criptografarString1`, `criptografarString2`, `descriptografarString1`, `descriptografarString2` são responsáveis pela manipulação do conteúdo dos arquivos.
- **Criação e Edição de Arquivos**: Funções como `criarArquivo` e `editarArquivo` permitem manipular arquivos em formato `.txt`.
- **Gerenciamento de Arquivos**: Funções para gerar nomes de arquivos aleatórios e para ler e escrever conteúdo criptografado nos arquivos.

---

## Como Executar o Projeto

### 1. Clone o Repositório

Para clonar este repositório, execute o seguinte comando:

```bash
git clone (https://github.com/paulohique/Algoritmo-de-Crip)
cd Algoritmo-de-Crip
```
## 2. Compile o Código
O código foi desenvolvido utilizando C. Para compilar, use o seguinte comando:

```bash
Copiar código
gcc -o criptografia arquivo.c
```
## 3. Execute o Programa
Para executar o programa, utilize o seguinte comando:
```bash
Copiar código
./criptografia
```
## 4. Interaja com o Programa
O programa irá exibir um menu de opções onde você pode escolher:

Criar um novo arquivo.
Editar um arquivo existente.
Descriptografar e ler um arquivo.
Escolher outro arquivo para descriptografar.
Sair do programa.
Exemplo de Uso
```bash
Copiar código
Selecione uma opção:
1. Criar arquivo
2. Editar arquivo
3. Descriptografar conteúdo do arquivo 'nome.txt'
4. Escolher outro arquivo para descriptografar
5. Sair
Opção: 1
Nome do arquivo gerado: 2d3A5b8F4c
Digite o conteúdo do arquivo:
Este é um conteúdo secreto!
Arquivo '2d3A5b8F4c.txt' criado com sucesso!
```
## Considerações
O algoritmo utiliza um deslocamento simples nos valores ASCII dos caracteres, o que não é recomendado para sistemas reais de criptografia.
Este projeto foi desenvolvido para fins educacionais, como parte de um exercício acadêmico da disciplina de Estruturas de Dados.
A criptografia implementada não é segura para uso em produção, sendo mais uma demonstração de manipulação de texto e arquivos em C.
