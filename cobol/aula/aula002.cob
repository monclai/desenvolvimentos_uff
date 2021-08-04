       IDENTIFICATION DIVISION.
       PROGRAM-ID. AULA002.

       DATA DIVISION.
       
       WORKING-STORAGE SECTION.
       
       77 WS-NOME      PIC X(20) VALUE SPACES.
       77 WS-DATA      PIC 9(06) VALUE ZEROS.
       77 WS-DAY


       PROCEDURE DIVISION.
       

      *      ACCEPT WS-NOME.
      *      DISPLAY "OLA! "WS-NOME.

           ACCEPT WS-DATA FROM DATE.
           DISPLAY WS-DATA.
      *    DATA NO FORMATO AMERICANO.
           

    
       

            STOP RUN.
            
       