CelulaLista maiorPilha() throws Exception{
    if(inicio==null){
        throw new Exception("ERRO");
    }
    CelulaLista maior = inicio;
    int contMaior=0, cont=0;
    for(CelulaPilha i = topo; i!=null; i=i.prox){
        contMaior++;
    }
    for(CelulaLista i = inicio.prox; i!=null; i=i.prox){
        for(CelulaPilha j = topo; j!=null; j=j.prox){
            cont++;
        }
        if(cont>contMaior){
            contMaior=cont;
            maior=i;
        }
        cont=0;
    }
    return maior;
}