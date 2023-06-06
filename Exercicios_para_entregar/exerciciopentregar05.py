termos = int(input("Quantos termos? "))

fibonacci = [0, 1]

if termos <= 0:
    print("Por favor, insira um número inteiro positivo.")
elif termos == 1:
    print(f"Sequência de Fibonacci:{fibonacci[0]}")
else:
    print("Sequência de Fibonacci:")
    print(fibonacci[0])
    print(fibonacci[1])
    for i in range(2, termos):
        proximo = fibonacci[i-1] + fibonacci[i-2]
        fibonacci.append(proximo)
        print(proximo)