#include <plib.h>


/*
    From HwGetScanCodes:

    The first number in each box gives the element of the
    array at BX used for that key (first element 0), and the second number gives the hexadecimal mask
    which, when ANDed with that array element, gives a non-zero result if that key is down. For example, on a
    Series 3a if the Control key is being pressed, element 2 of the array ANDed with hex 80 is non-zero.
*/

GLDEF_C VOID IsKeyDown(VOID) {
    UWORD scans[10];
    UINT i, j, flag = FALSE;

    p_getscancodes(&scans[0]);
    for (i=0; i<10; i++) {
        if (scans[i]) {
            flag = TRUE;
            for (j=0; j<16; j++) {
                if (scans[i] & (1 << j)) {
                    p_printf("COL%d:ROW%d (%04x) [%x:%016b]", i, j, 1 << j, i, scans[i]);
                }
            }
        }
    }
    if (flag) p_printf("");
}


GLDEF_C VOID main(VOID) {
    p_printf("KeyScan 0.0.1: Tells you the ROW and COL of a key");
    p_printf("To exit, press Psion-Esc\n");
    
    p_printf("Ready and waiting...");
    while (1) {
        IsKeyDown();
        p_sleep(5);
    }
}
