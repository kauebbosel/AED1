int maximumGain(char* s, int x, int y) {
    int retorno = 0, melhorRes = 0, piorRes = 0;
    char topo[3], chao[3];
    if(x < y ){                 //determina prioridade baseado na quantidade de pontos ganha qnd BA ou AB
        strcpy(topo, "ba");
        melhorRes = y;  
        strcpy(chao, "ab");
        piorRes = x;
    } else{
        strcpy(topo, "ab");
        melhorRes = x;
        strcpy(chao, "ba");
        piorRes = y;
    }

    char pilha[strlen(s) + 1];              //botamos o tamanho para garantir que ele lerá toda a string
    int tamPilha = 0;

    for(int i = 0; s[i] != '\0'; i++){              
        char atual = s[i];

        if( atual == topo[1] && tamPilha > 0 && pilha[tamPilha - 1] == topo[0]) {    //caso o caractere atual seja igual ao A ou B (dependendo da prioridade), a pilha não estar vazia e caso o próximo tenha o resultado uma combinação desejada, adicionaremos os pontos e diminuiremos o tamanho da pilha, caso seja falso,  aumentaremos a var tamPilha e modificaremos o tamanho da pilha para que seja igual ao elemento atual que está sendo lido no for loop.
            retorno = retorno + melhorRes;
            tamPilha--;
        } else{
            pilha[tamPilha++] = atual;
        }
    }

    char outraPilha[strlen(s) + 1];
    int tamOutraPilha = 0;
    
    for(int i = 0; i < tamPilha; i++){
        char atual = pilha[i];

        if(atual == chao[1] && tamOutraPilha > 0 && outraPilha[tamOutraPilha - 1] == chao[0]) { //aqui temos a mesma lógica do for loop anterior, porém para caso a variável não seja a de maior prioridade
            retorno = retorno + piorRes;
            tamOutraPilha--;
        } else{
            outraPilha[tamOutraPilha++] = atual;
        }
    }

    return retorno;
}
