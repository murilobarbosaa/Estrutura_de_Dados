numero = int(input("Digite um número inteiro entre 1 e 10: "))

if numero < 1 or numero > 10:
    print("Número inválido. Por favor, escolha um número entre 1 e 10.")
else:
    print(f"Tabuada do número {numero}:")
    for i in range(1, 11):
        resultado = numero * i
        print(f"{numero} x {i} = {resultado}")