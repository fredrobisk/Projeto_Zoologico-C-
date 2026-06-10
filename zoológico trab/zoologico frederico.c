#include <stdio.h>
#include <string.h> //adicionando a biblioteca string

struct cadastro { //criando no topo do codigo a declaracao da struct
    int codigo; //coodigo de identificacao dos animais
    char raca[100]; //raça do animal, no código estará raca o tempo inteiro para dar erro
    char data[30]; //defini data como uma string para guardar simbolos como barra e um numero extenso
    char sexo[5];  //sexo deifini com 5 caso aja mais letras digitadas pelo usuario, mas o certo é apenas o f ou m.
    int idade; //idade que defini o animal 
};
	//defini contadores globais para contar quantos animais por sexo e idade vou possuir durante o código inteiro
int countF = 0; //contador do sexo FEMININO
int countM = 0; //contador do sexo MASCULINO
int idadeTotalF = 0; //defini essa variavel para armazenar a idade de todos os animais FEMININOS
int idadeTotalM = 0; //defini essa para para armazenar a idade de todos os animais MASCULINOS

struct cadastro realizando(struct cadastro zoo) { //chamada funcao para ralizar o cadastro dos animais
    printf("\nCADASTRANDO ANIMAL:");
    printf("\nInsira o novo codigo: "); //inserindo o codigo
    scanf("%d", &zoo.codigo); //scanf para definir o codigo do animal
    getchar();  //limpa a entrada para nao dar erro de compilacao

    printf("\nDigite a raca do animal: "); //raca me refiro tambem ao tipo e o que é
    gets(zoo.raca); //inserindo a raça

    printf("\nData de entrada do animal (utilize barras): "); //colocando a data de entrada do animal
    gets(zoo.data);

    printf("\nDigite o sexo do animal (M para masculino e F para feminino): "); //definindo sexo
    gets(zoo.sexo);

    printf("\nDigite a idade do animal: ");
    scanf("%d", &zoo.idade); //definindo idade
    getchar();  // repare que utilizei o getchar para os scanfs e gets ao final para nao se atrapalhar o codigo

    if (strcmp(zoo.sexo, "F") == 0 || strcmp(zoo.sexo, "f") == 0) { //aqui eu descubro o sexo do animal utilizando e acrescentando as variaveis globais 
        countF++; //caso seja feminina o animal acrescenta a variavel global.
        idadeTotalF += zoo.idade; // nessa linha estou somando as idades para depois descobrir a media
    } else {
        countM++; //acrescentando caso seja masculino na variavel global
        idadeTotalM += zoo.idade; //somando as idades masculinas para descobrir a media depois
    }

    return zoo; //retorna a variavel preenchida para uma dimensao do vetor na linha 155
}

void descobrindo(struct cadastro zoo[], int total) { //nessa linha é quando o usuario digita 2 e quer pesquisar os aniamis
    char letra; //para descobrir o que o usuario deseja 
    printf("\na. Pesquisar por raca?");
    printf("\nb. Pesquisar por sexo?\n");
    scanf("%c", &letra);
    getchar();

    if (letra == 'a' || letra == 'A') { //caso o usuario desejar descobrir por raça ele entra em uma nova funcao
        raca(zoo, total); //entra nessa funcao logo abaixo para descobrir o animal pela raça
    } else if (letra == 'b' || letra == 'B') { //caso queira pesquisar por sexo entra nessa funcao abaixo
        sexo(zoo, total); //...
    }
}

void sexo(struct cadastro zoo[], int total) { //chamada funcao para descobrir animal pelo sexo
    char sexo_novo[5]; //criei uma nova variavel para o usuario inserir qual animal ele quer descobrir pelo sexo
    printf("Digite o sexo do animal: ");
    gets(sexo_novo); //ele só podera digitar M ou F, entao o codigo descobrirá os animais pelo sexo inserido 

    for (int i = 0; i < total; i++) { //entrando no laço para encontrar no vetor da struct zoo algum animal pelo sexo inserido
        if (strcmp(zoo[i].sexo, sexo_novo) == 0) { //utilizei um strcmp para encontrar, caso encontre o valor dará 0 e entrará nas proximas linhas 
            printf("\nAnimal encontrado:");
            printf("\nCodigo: %d", zoo[i].codigo); //printando codigo do animal
            printf("\nRaca: %s", zoo[i].raca); //...
            printf("\nData: %s", zoo[i].data); //...
            printf("\nSexo: %s", zoo[i].sexo); //aqui será printado o sexo do animal e tambem o digitado
            printf("\nIdade: %d\n", zoo[i].idade); //...
        }
    }
    getchar();//para pausar o sistema um pouco e se quiser continuar pressione ENTER
}

        //o sistema para encontrar a raça está identico ao do sexo, utilizei a mesma lógica
void raca(struct cadastro zoo[], int total) { //chamada funcao para descobrir o animal pela raça
    char raca_nova[20]; //nova variavel para  o usuario inserir a raca que deseja encontrar
    printf("Digite a raca do animal: "); 
    gets(raca_nova); //inserindo a raça que deseja encontrar

    for (int i = 0; i < total; i++) { //varrendo o vetor para encontrar 
        if (strcmp(zoo[i].raca, raca_nova) == 0) { //cmp para verificar se encontrou no vetor
            printf("\nAnimal encontrado:");
            printf("\nCodigo: %d", zoo[i].codigo);	//...
            printf("\nRaca: %s", zoo[i].raca);	//aqui será printado o que o usuario inseriu e a raça
            printf("\nData: %s", zoo[i].data);	//...
            printf("\nSexo: %s", zoo[i].sexo);	//...
            printf("\nIdade: %d\n", zoo[i].idade); //...
        }
    }
    getchar(); //...mesma coisa que o da linha 76
}

void gerarRELATORIO(struct cadastro zoo[], int total) { //chamada funcao para gerar um relatorio de todos os animais 
    if (total == 0) { //caso nao tenha cadastrado nenhum animal na main, sera postado a seguinte mensagem
        printf("Nenhum animal cadastrado.\n");
        return; //retorna para a main onde possui o laço 
    }
    printf("\nMostrando todos os animais cadastrados\n");
    for (int i = 0; i < total; i++) { //mostrando todos animais cadastrados até onde foi cadastrado
        printf("\nAnimal %d:", i + 1); //aqui mostram quantos animais foram cadastrados
        printf("\nCodigo: %d", zoo[i].codigo); //printando codigo...
        printf("\nRaca: %s", zoo[i].raca); //...
        printf("\nData: %s", zoo[i].data); //...
        printf("\nSexo: %s", zoo[i].sexo); //...
        printf("\nIdade: %d\n", zoo[i].idade); //...
    }
}

void apresentacao(struct cadastro zoo[], int total) { //chamada funcao caso o usuario digite 4 na main 
    char letra; //para descobrir o que o usuario deseja
    printf("\na. Apresentar total de animais por sexo");
    printf("\nb. Apresentar a media de idade de animais por sexo\n");
    scanf("%c", &letra);
    getchar();//...

    if (letra == 'a' || letra == 'A') { //verifica se o usuario deseja ver os animais por sexo
        printf("\nTODOS os Animais por Sexo:");
        printf("\nTotal de animais masculinos: %d", countM); //utiliza as variavesi globais armazenadas e printa nesta linha 
        printf("\nTotal de animais femininos: %d\n", countF); //utiliza a variavel global durante todo o codigo e printa nessa linha
        
    } else if (letra == 'b' || letra == 'B') { //verifica se o usuario deseja ver a media dos animais por sexo
        if (countM > 0) { //verifica se possui algum animal MASCULINO
            printf("\nMedia de idade dos animais masculinos: %.2f", (float)idadeTotalM / countM); /*nesta linha utilizei uma coisa não apresentada em aula, o CAST,
			o cast foi algo que descobri durante os execicios e durante o semestre, ele aplica dentro do printf ou que seja para realizar um print de um valor diferente 
			por exemplo: minha variavel global é int mas quero a media em float, utilizei o cast na linha 128 para me devolver um resultado com virgula.*/
        } else {
            printf("\nNenhum animal masculino cadastrado."); //caso nao tenha cadastrado nenhum animal masculino 
        }

        if (countF > 0) { //verifica se possui animal FEMININO
            printf("\nMedia de idade dos animais femininos: %.2f", (float)idadeTotalF / countF); //essa linha está explicada na linha 128, caso esteja confuso(a) eu tambem expliquei no video.
        } else {
            printf("\nNenhum animal feminino cadastrado.");//...linha 132
        }
    }
}

int main() { //aqui começamos o codigo 
    struct cadastro zoo[20];  // definindo as variaveis
    int n, i, j = 2, total = 0;// total será nossa variavel primordial e principal

    for(i= 0 ; i < j ; i++) {  // nesse laço eu fiz ser infinito, onde j é sempre acrescentado com mais 1 e i menor sempre que J, entao o laço é infinito
        printf("\n\tMENU"); //apresentando menu 
        printf("\n1. Cadastrar Animal.");
        printf("\n2. Pesquisar");
        printf("\n3. Relatorio");
        printf("\n4. Animais por sexo");
        printf("\n5. Sair\n");
        scanf("%d", &n); //o que o usuario desejar 
        getchar();  //nosso primeiro get para limpar o buffer
        system("cls"); //limpa a tela
        j++; //acrescenta o j para que nao seja finito o laço
        if (n == 1) {
            zoo[total] = realizando(zoo[total]);//LINHA 17 caso o usuario desejar cadastrar algum animal, ele entra nessa funcao e vai para linha 17.
            total++;//total agora é o nosso numero de vetor e aqui ele é acrescentado para ir em outra dimensao 
        } else if (n == 2) {
            descobrindo(zoo, total); //LINHA 47 nessa linha chama a funcao para pesquisar os animais
        } else if (n == 3) {
            gerarRELATORIO(zoo, total); //LINHA 98 nessa é para gerar o relatorio de todos os animais cadastrados
        } else if (n == 4) {
            apresentacao(zoo, total); //LINHA 144 nessa linha é para apresentar a media dos animais por sexo
        } else if (n == 5) { //aqui é para quebrar o laço e terminar o código.
            break;
        }
    }

    return 0;
}
