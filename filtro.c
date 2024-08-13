#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char *topico;
    char *palavras_chave[21];
    int num_palavras_chave;
    int repeticoes;
    char *JAFOI[20];
}Topico;


bool palavra_eh_palavra_chave(char palavra[], Topico *topico){
    for(int i = 0; i < topico->num_palavras_chave - 1; ++i){
        if(strcmp(palavra, topico->palavras_chave[i]) == 0){
            topico->repeticoes++;
            if(topico->JAFOI[i] != "JAFOI"){
                topico->JAFOI[i] = "JAFOI";
                return true;
            }
        }
    }
    return false;
}

int verifica_topico(char texto[], Topico *topico){
    int contador = 0;
    char palavra[500];
    int j = 0;
    for(int i = 0; texto[i] != '\0'; ++i){
        if(isspace(texto[i]) && texto[i] != '-'){
            if(j > 0){
                palavra[j] = '\0';
                if(palavra_eh_palavra_chave(palavra, topico)){
                    contador++;
                }
                j = 0;
            }
        }else{
            palavra[j++] = texto[i];
        }
    }
    return contador;
}

int main(){
    Topico topicos[]={
        {"alimentacao", {"comida", "dieta", "nutricao", "restaurante", "receita", "gastronomia", "culinaria",
                         "chef", "sabor", "ingrediente", "cozinha", "saudavel", "gourmet", "vegetariano",
                         "organico", "sobremesa", "gourmet", "alimentacao", "fast"}, 19, 0, {NULL}},
        {"arte", {"pintura", "escultura", "galeria", "artista", "criatividade", "exposicao", "obra",
                  "museu", "contemporaneo", "estilo", "retrato", "abstrato", "tecnica", "estetica",
                  "inspiracao", "urbana", "performance", "visual", "artistico", "NULL"}, 20, 0, {NULL}},
        {"cinema", {"filme", "ator", "diretor", "cena", "roteiro", "cinema", "producao", "elenco",
                    "premiacao", "blockbuster", "suspense", "comedia", "drama", "acao",
                    "animacao", "efeitos", "trilha", "classico", "critica"}, 19, 0, {NULL}},
        {"educacao", {"aprendizado", "escola", "professor", "aluno", "conhecimento", "educacao",
                      "ensino", "aprendizagem", "pedagogia", "curriculo", "aula", "didatica",
                      "formacao", "universidade", "pesquisa", "leitura", "escrita", "alfabetizacao",
                      "disciplina"}, 19, 0, {NULL}},
        {"esporte", {"esporte", "jogo", "jogador", "equipe", "competicao", "treinamento", "atleta",
                     "vitoria", "derrota", "torneio", "modalidade", "arbitro", "ginasio",
                     "condicionamento", "estrategia", "desempenho", "torcedor", "medalha",
                     "performance", "recorde", "NULL"}, 21, 0, {NULL}},
        {"meio ambiente", {"natureza", "sustentabilidade", "ecossistema", "poluicao", "conservacao",
                           "ambientalismo", "biodiversidade", "clima", "desmatamento", "reciclagem",
                           "renovavel", "preservacao", "fauna", "flora", "aquecimento", "ecologia",
                           "conscientizacao", "ambiental"}, 19, 0, {NULL}},
        {"negocios", {"empresa", "mercado", "investimento", "empreendedorismo", "lucro", "gestao",
                      "negociacao", "economia", "financas", "estrategia", "marketing", "cliente",
                      "produto", "concorrencia", "inovacao", "start-up", "planejamento", "lideranca",
                      "networking"}, 20, 0, {NULL}},
        {"saude", {"saude", "medicina", "paciente", "doenca", "tratamento", "hospital",
                   "diagnostico", "cuidados", "terapia", "prevencao", "medico", "enfermagem",
                   "farmacia", "vacinacao", "pesquisa", "bem-estar", "cirurgia", "mental",
                   "epidemia", "imunizacao"}, 20, 0, {NULL}},
        {"tecnologia", {"computador", "software", "ia", "internet", "dispositivo", "programacao",
                        "inovacao", "celular", "algoritmo", "digitalizacao", "seguranca", "conectividade",
                        "hardware", "rv", "software livre", "automacao", "ciberseguranca", "plataforma",
                        "nanotecnologia", "robotica"}, 20, 0, {NULL}},
        {"viagens", {"destino", "turismo", "aventura", "hospedagem", "experiencia", "viagem",
                     "roteiro", "passeio", "cultura", "lazer", "explorar", "descobrir", "turista", "paisagem",
                     "guia", "hospedaria", "passeio", "ferias", "itinerario"}, 20, 0, {NULL}},
    };

    char texto[5000];
    fgets(texto, sizeof(texto), stdin);

    for(int i = 0; texto[i]; i++){
        texto[i] = tolower(texto[i]);
        if(!isalnum(texto[i]) && !isspace(texto[i]) && texto[i] != '-'){
            texto[i] = ' ';
        }
    }
    

    int encontrados = 0;
    int P = -1, S = -1, T = -1, Q = -1;
    int contagem[10];
    for(int i = 0; i < 10; ++i){
        contagem[i] = verifica_topico(texto, &topicos[i]);
        if(contagem[i] >= 5){
            if(encontrados == 0){
                printf("Topico(s):\n");
                P = i;
            }else if (encontrados == 1){
                S = i;
            }else if(encontrados == 2){
                T = i;
            }else if(encontrados == 3){
                Q = i;
            }
            encontrados++;
        }
    }

    if(encontrados > 2){
        printf("misto\n");
    }else if(encontrados == 0){
        printf("O texto nao possui nenhum topico\n");
    }else{
        if(P != -1){
            printf("%s\n", topicos[P].topico);
        }
        if(S != -1){
            printf("%s\n", topicos[S].topico);
        }
        if(T != -1){
            printf("%s\n", topicos[T].topico);
        }
        if(Q != -1){
            printf("%s\n", topicos[Q].topico);
        }
    }
    
    if(encontrados > 0){
        printf("Contabilização:\n");
        if(P != -1){
            printf("%s - %i palavra(s)\n", topicos[P].topico, topicos[P].repeticoes);
        }
        if(S != -1){
            printf("%s - %i palavra(s)\n", topicos[S].topico, topicos[S].repeticoes);
        }
        if(T != -1){
            printf("%s - %i palavra(s)\n", topicos[T].topico, topicos[T].repeticoes);
        }
        if(Q != -1){
            printf("%s - %i palavra(s)\n", topicos[Q].topico, topicos[Q].repeticoes);
        }
    }

    return 0;
}
