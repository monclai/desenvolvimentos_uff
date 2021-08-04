       identification division.
       program-id. copia_dados.

      *================================================================= 
       environment division.
      *================================================================= 
       input-output section.
      *----------------------------------------------------------------- 
       file-control.

       select arq-entrada
           assign to "alunos.dat"
           organization is line sequential
           access is sequential
           file status is ws-fs.

       select arq-saida
           assign to "saida.dat"
           organization is line sequential
           access is sequential
           file status is ws-fs2.
      
      *================================================================= 
       data division.
      *=================================================================
       file section.
      *-----------------------------------------------------------------

       fd arq-entrada.
       01 reg-data.
           02 alu-num      pic 9(03).
           02 alu-nome     pic a(25).

       fd arq-saida.
       01 reg-saida.
           02 saida-nome   pic a(25). 

      *----------------------------------------------------------------- 
       working-storage section.
      *-----------------------------------------------------------------
       77 ws-fs            pic 99.
       77 ws-fs2           pic 99.
       01 ws-alu.
           02 ws-alunum    pic 9(03).
           02 ws-alunome   pic a(25).

       01 ws-eof           pic a(01).

      *================================================================= 
       procedure division.
      *=================================================================

      *----------------------------------------------------------------- 
       a01-processa.
      *-----------------------------------------------------------------  
 
       open input arq-entrada.
       if ws-fs <> 0
           display "erro de abertura ws-fs: " ws-fs
           close arq-entrada
           stop run.

       open output arq-saida.
       if ws-fs2 <> 0 
           display "erro de abertura ws-fs2: " ws-fs2
           close arq-saida
           stop run.

       perform until ws-eof = "y"
           read arq-entrada into ws-alu
               at end move "y" to ws-eof
               not end perform a02-imprime
            end-read
       end-perform.

       close arq-entrada arq-saida.
       stop run.

      *----------------------------------------------------------------- 
       a02-imprime.
      *----------------------------------------------------------------- 

       display ws-alu.
       move ws-alunome to saida-nome.
       write reg-saida. 