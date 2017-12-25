#include <stdio.h>
#include <stdbool.h>
int main(){
    int melhor_soma = -1,melhor_de,melhor_ate,de = 1,soma = 0,partida,partidas,teste = 1,favor,contra;
    while(true){
        scanf("%d",&partidas);
        if(!partidas) break;
        soma = 0;
        de = 1;
        melhor_soma = -1;
        printf("Teste %d\n",teste++);
        for(partida = 1;partida<=partidas;partida++){
            favor = contra = 0 ;
            scanf("%d %d",&favor,&contra);
            soma += favor - contra;
            if(soma < 0){
                de = partida + 1 ;
                soma = 0;
            }
            else if( soma > 0 && (soma > melhor_soma || soma == melhor_soma && partida-de >= melhor_ate-melhor_de )){
                melhor_soma = soma;
                melhor_de = de;
                melhor_ate  = partida;
            }
        }
        if(melhor_soma == -1)
            printf("nenhum\n\n");
        else
            printf("%d %d\n\n",melhor_de,melhor_ate);
            
    }
    
    return 0;
}
