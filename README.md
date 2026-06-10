# Projeto_Zoologico-C

# 🐾 Sistema de Cadastro de Zoológico

Projeto desenvolvido em linguagem C com o objetivo de simular o gerenciamento de animais de um zoológico, permitindo o cadastro, consulta e geração de relatórios através de um menu interativo no terminal.

---

## 📖 Sobre o Projeto

O Sistema de Cadastro de Zoológico foi desenvolvido para aplicar conceitos fundamentais da programação estruturada em C, utilizando estruturas de dados, funções e manipulação de strings.

O sistema permite cadastrar animais, realizar pesquisas específicas e gerar estatísticas sobre os registros armazenados, proporcionando uma experiência prática no desenvolvimento de aplicações de gerenciamento.

Durante o desenvolvimento foram utilizados diversos conceitos estudados em sala de aula, como:

- Estruturas (`struct`)
- Vetores
- Funções
- Variáveis globais
- Estruturas de decisão (`if/else`)
- Estruturas de repetição (`for`)
- Manipulação de strings (`strcmp`)
- Entrada e saída de dados
- Organização modular do código

---

## ✨ Funcionalidades

### 📝 Cadastro de Animais
Permite registrar novos animais informando:

- Código de identificação
- Raça/Espécie
- Data de entrada
- Sexo
- Idade

### 🔍 Pesquisa de Animais

O sistema permite pesquisar animais através de:

- Raça
- Sexo

### 📊 Relatórios

Geração de relatório contendo todos os animais cadastrados.

### 📈 Estatísticas

O sistema apresenta:

- Quantidade de animais masculinos
- Quantidade de animais femininos
- Média de idade dos animais masculinos
- Média de idade dos animais femininos

---

## 🛠️ Tecnologias Utilizadas

- Linguagem C
- Biblioteca `stdio.h`
- Biblioteca `string.h`

---

## 📋 Estrutura do Menu

```text
MENU

1. Cadastrar Animal
2. Pesquisar
3. Relatório
4. Animais por Sexo
5. Sair
```

---

## ▶️ Como Executar

### Compilar

Utilizando GCC:

```bash
gcc zoologico.c -o zoologico
```

### Executar

Linux:

```bash
./zoologico
```

Windows:

```bash
zoologico.exe
```

---

## 📚 Conceitos Aplicados

Este projeto foi desenvolvido para praticar:

- Programação Estruturada
- Organização de código em funções
- Manipulação de vetores de estruturas
- Busca de registros
- Cálculo de estatísticas
- Entrada e saída de dados em C

---

## 🎓 Contexto Acadêmico

Projeto desenvolvido para a disciplina de Programação da Universidade Federal de Santa Maria (UFSM).

O objetivo principal foi exercitar os fundamentos da linguagem C através da implementação de um sistema de gerenciamento simples, consolidando conhecimentos sobre estruturas de dados, funções e lógica de programação.

---

## 🚀 Possíveis Melhorias Futuras

- Persistência de dados em arquivos
- Edição de registros cadastrados
- Exclusão de animais
- Interface gráfica
- Busca por código de identificação
- Validação de entradas do usuário
- Substituição da função `gets()` por métodos mais seguros
