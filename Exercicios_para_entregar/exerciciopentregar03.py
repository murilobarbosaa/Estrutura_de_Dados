numeros = []

while True:
    numero = input("Digite um número (ou 's' para sair): ")
    if numero.lower() == 's':
        break

    numeros.append(int(numero))

quantidade = len(numeros)
soma = sum(numeros)

numeros_pares = 0
for num in numeros:
    if num % 2 == 0:
        numeros_pares += 1

porcentagem_pares = (numeros_pares / quantidade) * 100

print("Quantidade de elementos:", quantidade)
print("Soma dos valores:", soma)
print("Média dos valores:", soma / quantidade)
print(f"Porcentagem de números pares: {porcentagem_pares:.2f}")