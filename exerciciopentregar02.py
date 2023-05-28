#Cálculo da média:

nota1 = float(input("Digite sua primeira nota: "))
nota2 = float(input("Digite sua segunda nota: "))
nota3 = float(input("Digite sua terceira nota: "))

if nota1 < 0 or nota1 > 10:
    print("O valor das notas que você digitou é inválido")
else:
    if nota2 < 0 or nota2 > 10:
        print("O valor das notas que você digitou é inválido")
    else:
        if nota3 < 0 or nota3 > 10:
            print("O valor das notas que você digitou é inválido")
        else:
            media = (nota1 + nota2 + nota3) / 3
            print(f"Sua média foi: {media:.2f}")

if media < 7:
    print("Você foi reprovado")
else:
    print("Você foi aprovado")