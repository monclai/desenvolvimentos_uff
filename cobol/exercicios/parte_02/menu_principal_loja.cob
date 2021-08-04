       identification division.
       program-id. menu_principal_loja.

       data division.
       
       working-storage section.
       
       77 opcao pic 9(01) value zero.
       77 dummy pic x(01).

       screen section.

       01 menu-principal.
           02 blank screen.
           02 line 1 col 1 value "------------------------------------".
           02 line 2 col 2 value "Sistema de compra/venda Mercadorias".
           02 line 3 col 1 value "------------------------------------".
           02 line 4 col 33 value "Menu principal".
           02 line 7 col 10 value "[1] Cadastro mercadoria".
           02 line 8 col 10 value "[2] Cadastro cliente".
           02 line 9 col 10 value "[3] Cadastro vendedor/comprador".
           02 line 10 col 10 value "[4] Listagem de mercadoria".
           02 line 11 col 10 value "[5] Listagem de cliente".
           02 line 12 col 10 value "[6] Sair sistema".
           02 line 15 col 10 value "Digite a opcao desejada:  ".
           02 line 15 col 35 pic 9 using opcao auto.

       procedure division.
       
       inicio.
           display menu-principal.
           accept menu-principal.
           evaluate opcao
               when 1
                  display " cadastro de mecadoria selecionado"
                   accept dummy                   
                  go to inicio
                when 2
                   display " cadastro de cliente selecionado"
                   accept dummy                   
                   go to inicio
                when 6
                   stop run
               when other
                  go to inicio
           end-evaluate.


           stop run.