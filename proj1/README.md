# PROJETO 1 – SISTEMAS OPERACIONAIS
PROFESSOR: EDUARDO FERREIRA DOS SANTOS

Grupo: Grupo 5  
Membro: Murilo Kenichiro Senaga  
TTIA: 42127785

Este documento contem as instruções detalhadas para execução do problema de transferência de fundos entre duas contas to e from.

# Compilação do programa na plataforma AWS
Para compilar o arquivo main.c na aws, voce deve ter instalado em sua maquina o compilador gcc. Com o compilador instalado, sera possivel compilar o arquivo main.c e para isso voce deve digitar o seguinte comando:  
`gcc -lpthread -o arquivo.exe main.c`  
Este comando criará um arquivo executável chamado arquivo.exe. Voce pode trocar o nome do arquivo executavel para qualquer outro que preferir.

# Execução do programa
Para executar o programa, use o seguinte comando:  
`./arquivo.exe` ou `./(nome do arquivo)`

# Resultados propostos
1.2. A conta to pode receber mais de uma transferência simultânea e conta from pode enviar mais de uma transferência simultânea:  
![Imagem1](/imgs/img1.png)

3. A conta from não pode enviar dinheiro se não tiver mais saldo:  
![Imagem1](/imgs/img1.png)

4. A conta to pode trocar de ordem com a conta from, ou seja, a conta que enviava pode receber e a conta que recebia pode enviar:  
Não foi possivel atingir o requisito 4 do problema.

5. Poderão ser realizadas até 100 transações simultâneas de transferência:  
![Imagem1](/imgs/img1.png)

