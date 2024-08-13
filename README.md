# Classificação de Texto por Palavras-Chave

# Descrição
Este projeto implementa um algoritmo de classificação de texto baseado na contagem de palavras-chave associadas a tópicos específicos. A aplicação é útil para categorizar textos em áreas como tecnologia, saúde, esporte, entre outros, com base na presença e frequência de termos específicos.
Codigo estilo Verde / BEECROWD (correcao das saidas por IA);

# Funcionamento
O algoritmo analisa textos e os classifica em tópicos predefinidos, exigindo a presença de pelo menos cinco palavras-chave distintas para que um tópico seja considerado. Se o texto abranger mais de dois tópicos, ele é classificado como "misto". A análise é case-insensitive, contando todas as ocorrências, independentemente de maiúsculas ou minúsculas.

# Exemplo de Entradas e Saídas


# Entrada 1:

Em meio ao burburinho da cidade, o museu de arte moderna se erguia como um oasis de criatividade. La dentro, obra de arte de todos os estilo e epocas se entrelacavam, convidando o olhar a se perder em cores, formas e texturas. Entre os visitantes, um jovem cineasta, fascinado pela beleza e expressividade das pintura e escultura, buscava inspiracao para seu proximo filme. Ao observar uma pintura abstrato de tons vibrantes, o cineasta imaginou uma cena de acao em que os personagens se moviam em perfeita sincronia com as cores e formas da obra. Ja diante de uma escultura imponente, ele vislumbrou um drama sobre a luta do artista para expressar seus sentimentos atraves da arte. Cada obra era um portal para um universo de possibilidades cinematograficas, agucando a imaginacao do jovem diretor.

# Saída 1:

Topico(s):

arte

cinema

Contabilização:

arte - 13 palavra(s)

cinema - 5 palavra(s)


# Entrada 2:

No mundo do esporte contemporaneo, a tecnologia se tornou uma aliada poderosa para atleta e equipe. A utilizacao de dispositivo de monitoramento e analise de dados revolucionou o treinamento e a performance dos atleta. Desde a implementacao de algoritmo para otimizar estrategia ate o uso de rv para simular situacoes de jogo, a tecnologia esta redefinindo os limites do desempenho esportivo. Alem disso, na area da saude, a intersecao entre tecnologia e medicina esta transformando os cuidados com os atleta. Diagnostico mais precisos, tratamento personalizados e ferramentas de monitoramento remoto estao contribuindo para a prevencao de lesoes e a maximizacao do bem-estar fisico dos praticantes de esporte de alto rendimento. Na vanguarda da inovacao, a saude e a tecnologia unem-se para impulsionar o desempenho esportivo e garantir o bem-estar dos atleta. Atraves da ia e da digitalizacao, novas solucoes surgem para otimizar o diagnostico e tratamento de lesoes, enquanto dispositivo conectados oferecem monitoramento em tempo real da saude dos esportistas. Essa sinergia entre esporte, saude e tecnologia nao so eleva o nivel de competicao, mas tambem promove uma abordagem mais holistica e preventiva para a saude dos praticantes de atividades fisicas..

# Saída 2:

Topico(s):

misto

Contabilização:

esporte - 15 palavra(s)

saude - 12 palavra(s)

tecnologia - 7 palavra(s)


# Entrada 3:

Entre os murmurios suaves do vento e os raios dourados do sol poente, a cidade adormecida desperta para a promessa de uma nova aurora, onde os sonhos se entrelacam com a realidade e as possibilidades sao tao vastas quanto o horizonte que se estende diante de nos.

# Saída 3:

O texto nao possui nenhum topico



# Conclusão
Este projeto oferece uma ferramenta eficiente para a categorização automática de textos em tópicos, podendo ser aplicada em diferentes contextos de análise de linguagem natural.

