identification division.
PROGRAM-ID. TESTE-CPF.
DATA DIVISION.
WORKING-STORAGE SECTION.
    77 CPF PIC X(14).
    77 P1_CPF PIC 9(3).
    77 P2_CPF PIC 9(3).
    77 P3_CPF PIC 9(3).
    77 P4_CPF PIC 9(2).
    77 NCPF_1 REDEFINES P1_CPF PIC 9(1) OCCURS 3.
PROCEDURE DIVISION.
    DISPLAY "DIGITE SEU CPF".
    ACCEPT CPF.
    UNSTRING CPF DELIMITED BY "." OR "-"
        INTO P1_CPF, P2_CPF, P3_CPF, P4_CPF
    END-UNSTRING.
    DISPLAY P1_CPF.
    DISPLAY P2_CPF.
    DISPLAY P3_CPF.
    DISPLAY P4_CPF.
        
STOP RUN.