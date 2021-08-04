      *================================================================*
       IDENTIFICATION                              DIVISION.       
      *================================================================*
       PROGRAM-ID. AULA001.
      *================================================================*


      *================================================================*
       DATA                                        DIVISION.
      *================================================================*
      *----------------------------------------------------------------*
       working-storage                     section.
      *----------------------------------------------------------------*
      
      * Formato de declaração de variável em cobol:
      * <nível> <identificador> <tipo(tamanho)>

       77 NUMERO           PIC 9(18).
       77 NUMERO-SINAL     PIC S9(18).
       77 NUMERO-DECIMAL   PIC 9(07)V99.
       77 NOME             PIC A(20).
       77 NOME-NUMERO      PIC X(30).

      * Registros funcionam como structs em c, em devem ser declarados
      * usando o nível 01, tento como itens de grupo, itens elementares
      * podendo esses serem declados com níveis de 02 à 49

      * Itens de grupo são alfanuméricos por definição, dessa forma o
      * título do struct não precisa de tipo, pois é alfanumérico.
      * Podemos inicializar variáveis com a clausula "VALUE".

       01 CLIENTE.
           02 NOME         PIC X(20) VALUE "MATHEUS MONCLAI".
           02 RG           PIC X(15) VALUE "28.325.893-7". 
           02 CPF          PIC X(15) VALUE "146.146.107-55".
           02 ENDERECO     PIC X(20) VALUE "RUA ESTRELA DALVA".
      *    02 DATA-NASC    PIC X(08) VALUE "15111995".
           02 DATA-NASC.
               03 DIA PIC X(02) VALUE "15".
               03 MES PIC X(02) VALUE "11".
               03 ANO PIC X(04) VALUE "1995".
               66 MES-ANO RENAMES MES THRU ANO.
        
       78 MASCULINO VALUE "M".
        
       01 GENERO PIC X(01).
           88 MASCULINO    VALUE "M".
           88 FEMININO     VALUE "F".

      * Existe níveis especificos, alguns deles são:
      * 66: renomeia uma variável, redefine outras variáveis
      * 77: declaração de variáveis indenpendentes 
      * 78: declaração de constantes
      * 88: define nomes e condições 
      
      
      
      *================================================================*  
       PROCEDURE                                   DIVISION.
      *================================================================*
           DISPLAY "OLA MUNDO!".
           DISPLAY DATA-NASC
           SET MASCULINO TO TRUE.
           DISPLAY GENERO.

           STOP RUN.
      * Casso coloque um hifen(-) na linha 7, continua o conteudo da
      * anterior