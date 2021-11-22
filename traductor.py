def mujeres(lista):
    m=0
    for i in range(len(lista)):
        lista[i]=lista[i].lower()
        if(lista[i]=="mujer"):
            m=m+1
    return m
def hombres(lista):
    h=0
    for i in range(len(lista)):
        lista[i]=lista[i].lower()
        if(lista[i]=="hombre"):
            h=h+1
    return h

MH = ['hombre', 'mujer', 'MUJER', 'HOMBRE', 'MUJER','hombre', 'mujer', 'MUJER', 'HOMBRE', 'MUJER']
print("El numero de mujeres es:",mujeres(MH))
print("El numero de hombres es:",hombres(MH))