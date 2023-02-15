# Trabalho 2 GRUPO

# Aqui vai a introdução do código.

Este é um código em linguagem C que apresenta um sistema simples de gerenciamento de carros para aluguel. O código apresenta uma estrutura de dados struct Carro, que contém campos para a marca, modelo, placa, valor, valor do aluguel, ano e se o carro está ou não alugado.

O código implementa várias funções, incluindo liberar_memoria para liberar a memória alocada dinamicamente, cadastrar_carro para permitir o cadastro de novos carros, exibir_carros para exibir a lista de carros disponíveis, pesquisa_carros para pesquisar carros por placa, modelo ou ano, e alugar_carro para alugar um carro.

O programa é limitado a um máximo de 100 carros e usa alocação dinâmica de memória para armazenar e gerenciar os dados. O usuário é solicitado a inserir informações sobre os carros, como marca, modelo, placa, ano, valor e valor do aluguel. Em seguida, ele pode visualizar a lista de carros disponíveis, pesquisar um carro específico e alugá-lo.

O programa também inclui verificações de erro para garantir que a alocação de memória foi bem-sucedida e que as entradas do usuário são válidas. No entanto, o código não inclui verificação de entrada inválida ou limite máximo para o número de carros que podem ser alugados simultaneamente.

O programa iniciará perguntando se você é comprador ou vendedor, dependendo da resposta você terá opções disponíveis:

## Permissões vendedor

- Alocar quantidade de vagas na garagem;
- Realocar quantidade de vagas;
- Cadastrar novo carro;
- Precisará de algumas informações: preço, modelo, marca, ano, etc.
- Remover carro;
- Checar quantidade de clientes, e seus nomes;
- Permissões comprador:
- Comprar carro;
- Alugar carro;
- Ir embora (Encerra Programa);

 O sistema de identificação (vendedor ou comprador), será administrado por base de um banco de dados improvisado, utilizando arquivos
## Requisitos

- Matriz:
- Matriz de structs (informações dos carros).
- Vetor:
- Ordenação:
- Ordenar carros por preço, ordenar clientes por ordem alfabética,   ordenar por função (viagem, trabalho, etc)

