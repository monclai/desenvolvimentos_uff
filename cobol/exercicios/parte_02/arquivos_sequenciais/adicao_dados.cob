       identification division.
       program-id. lendo_dados.

       environment division.
       
       input-output section.

       file-control.

       select arq-entrada
           assign to "alunos.dat"
           organization is line sequential
           access is sequential
           file status is ws-fs.

       data division.
       
       file section.

       fd arq-entrada.
       01 reg-data.
           05 alu-num pic 9(03).
           05 alu-nome pic a(25).

       working-storage section.
       
       77 ws-fs pic 99.
       77 ws-flag pic 9 value 0.
       
       01 ws-alu.
           05 ws-alunum pic 9(03).
           05 ws-alunome pic a(25).

       01 ws-eof pic a(01).

       procedure division.
       
       a01-processa.

       open input arq-entrada.

       if ws-fs <> 0
           display "erro de abertura ws-fs: " ws-fs
           close arq-entrada
           stop run.

       perform until ws-eof = "y"
           read arq-entrada into ws-alu
               at end move "y" to ws-eof
               not end perform a02-imprime
            end-read
       end-perform.
       close arq-entrada.
       perform a03-inclui.
       stop run.

       a02-imprime.

       display ws-alu.
       
       a03-inclui.

       open extend arq-entrada.
       move 115 to alu-num.
       move "MESTRE LEE" to alu-nome.
       write reg-data.
       close arq-entrada.