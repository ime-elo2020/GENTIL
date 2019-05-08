void inicio();                                       

void (*isr[])() _attribute_ ((section (".vetor")))={ // declara o vetor de interrupção .vector
    (void (*) ())0x20020000,                         // atribui o endereço de retorno em caso de interrupção
    inicio
};

void inicio (){
    *((int*)(0x40023800 + 0x30))=0x08;              // habilita a porta D
    *((int*)(0x40020C00 + 0x00))=0x01000000;        // seta a porta D como output
    *((int*)(0x40020C00 + 0x04))=0x00000000;        // seta o output da porta D como push-pull
    *((int*)(0x40020C00 + 0x08))=0x00000000;        // seta o output da porta D como low speed
    *((int*)(0x40020C00 + 0x0c))=0x00000000;        // stea a porta D sem pull-up ou pull-down
    int ligado=0x1000;                              // declara variavel ligado com valor em hex 0x1000
    int desligado=0x0000;                           // declara variavel desligado com valor em hex 0x0000
    int i;                                          // declara variavel i
    int *ptr=(int*)(0x40020C00 + 0x14);             // declara ponteiro ptr que aponta para GPIOD_ODR
loop:                                               // label para o loop
    i=800000;                                       // atribui valor 800000 a variavel i
    *ptr=ligado;                                    // liga o LED 
    while(i--);                                     // loop que não faz nada, delay
    *ptr=desligado;                                 // desliga o LED 
    i=800000;                                       // reinicia o "contador" colocando a variavel i em 800000
    while(i--);                                     // loop que não faz nada, delay
    goto loop;                                      // volta para o início do loop
}