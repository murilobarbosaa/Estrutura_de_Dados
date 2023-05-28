#Calcular a área de um triângulo, com input e sem


#Sem usar input:
base = 10
altura = 10


area = (base * altura) / 2
print(f"O valor da área é: {area:.2f}")


#Usando input:
base = float(input("Digite o valor da base: "))
altura = float(input("Digite o valor da altura: "))


area = (base * altura) / 2
print(f"O valor da área é: {area:.2f}")