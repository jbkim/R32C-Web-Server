/************************************************************************************
*                                                                                   *
*   file name   : definition of R32C/111(100Y)'s SFR                                *
*                                                                                   *
*   Copyright   : RENESAS TECHNOLOGY CORPORATION                                    *
*                                                                                   *
*   Version     : 0.01  ( 2007-10-11 ) Initial [maked by Hardware manual Rev.0.01]  *
*   Version     : 0.10  ( 2008-02-28 )         [maked by Hardware manual Rev.0.10]  *
*       bit symbol is revised                                                       *
*           prdy in fmr0 is deleted                                                 *
*           cm16 in cm1 is addied                                                   *
*           cm31 in cm3 is addied                                               *   *
*                                                                                   *
*************************************************************************************/
/*
  note:
    This data is a freeware that SFR for R32C/100 groups is described.
 	Renesas Technology Corporation assumes no responsibility for any damage
 	that occurred by this data.
*/
/********************************************************
*   declare SFR addresses                               *
********************************************************/
#pragma ADDRESS     ccr_addr	0004H		/* Clock Control Register */
#pragma ADDRESS     fmcr_addr	0006H		/* Flash Memory Control Register */
#pragma ADDRESS     prr_addr	0007H		/* Protect Register */
#pragma ADDRESS     ebc3_addr	0010H		/* Outer Bus Control Register 3 */
#pragma ADDRESS     cb23_addr	0012H		/* Chip Select 2-3 Boundary Setting Register */
#pragma ADDRESS     ebc2_addr	0014H		/* Outer Bus Control Register 2 */
#pragma ADDRESS     cb12_addr	0016H		/* Chip Select 1-2 Boundary Setting Register */
#pragma ADDRESS     ebc1_addr	0018H		/* Outer Bus Control Register 1 */
#pragma ADDRESS     cb01_addr	001AH		/* Chip Select 0-1 Boundary Setting Register */
#pragma ADDRESS     ebc0_addr	001CH		/* Outer Bus Control Register 0 */
#pragma ADDRESS     febc_addr	001CH		/* Flash Memory Rewrite Bus Control Register */
#pragma ADDRESS     pbc_addr	001EH		/* Peripheal Bus Control Register */
#pragma ADDRESS     tb5ic_addr	0061H		/* timer b5 Interrupt Control Register */
#pragma ADDRESS     s5tic_addr	0062H		/* uart5 transmit/nack Interrupt Control Register */
#pragma ADDRESS     s2ric_addr	0063H		/* Uart2 Receive/Ack Interrupt Contorol Register */
#pragma ADDRESS     s6tic_addr	0064H		/* uart6 transmit/nack Interrupt Control Register */
#pragma ADDRESS     s3ric_addr	0065H		/* uart3 receive/ack iterrupt Control Register */
#pragma ADDRESS     bcn5ic_addr	0066H		/* bus collision (uart5) interrput Control Register */
#pragma ADDRESS     bcn6ic_addr	0066H		/* bus collision (uart6) interrput Control Register */
#pragma ADDRESS     s4ric_addr	0067H		/* uart4 receive/ack Interrupt Control Register */
#pragma ADDRESS     dm0ic_addr	0068H		/* Dma0 Interrupt Control Register */
#pragma ADDRESS     bcn0ic_addr	0069H		/* bus collision (uart0) interrput Control Register */
#pragma ADDRESS     bcn3ic_addr	0069H		/* bus collision (uart3) interrput Control Register */
#pragma ADDRESS     dm2ic_addr	006AH		/* Dma2 Interrupt Control Register */
#pragma ADDRESS     ad0ic_addr	006BH		/* a-d0 Interrupt Control Register */
#pragma ADDRESS     ta0ic_addr	006CH		/* Timer a0 Interrupt Control Register */
#pragma ADDRESS     iio0ic_addr	006DH		/* iio0 Interrupt Control Register */
#pragma ADDRESS     ta2ic_addr	006EH		/* timer a2 Interrupt Control Register */
#pragma ADDRESS     iio2ic_addr	006FH		/* iio2 Interrupt Control Register */
#pragma ADDRESS     ta4ic_addr	0070H		/* timer a4 Interrupt Control Register */
#pragma ADDRESS     iio4ic_addr	0071H		/* iio4 Interrupt Control Register */
#pragma ADDRESS     s0ric_addr	0072H		/* uart0 receive Interrupt Control Register */
#pragma ADDRESS     iio6ic_addr	0073H		/* iio6 Interrupt Control Register */
#pragma ADDRESS     s1ric_addr	0074H		/* uart1 receive Interrupt Control Register */
#pragma ADDRESS     iio8ic_addr	0075H		/* iio8 Interrupt Control Register */
#pragma ADDRESS     tb1ic_addr	0076H		/* timer b1 Interrupt Control Register */
#pragma ADDRESS     iio10ic_addr	0077H		/* iio10 Interrupt Control Register */
#pragma ADDRESS     tb3ic_addr	0078H		/* timer b3 Interrupt Control Register */
#pragma ADDRESS     int5ic_addr	007AH		/* int5 Interrupt Control Register */
#pragma ADDRESS     int3ic_addr	007CH		/* int3 Interrupt Control Register */
#pragma ADDRESS     int1ic_addr	007EH		/* int1 Interrupt Control Register */
#pragma ADDRESS     s2tic_addr	0081H		/* uart2 transmit/nack Interrupt Control Register */
#pragma ADDRESS     s5ric_addr	0082H		/* uart5 receive/ack Interrupt Control Register */
#pragma ADDRESS     s3tic_addr	0083H		/* uart3 transmit/nack Interrupt Control Register */
#pragma ADDRESS     s6ric_addr	0084H		/* uart6 receive/ack Interrupt Control Register */
#pragma ADDRESS     s4tic_addr	0085H		/* uart4 transmit/nack Interrupt Control Register */
#pragma ADDRESS     bcn2ic_addr	0087H		/* bus collision (uart2) interrput Control Register */
#pragma ADDRESS     dm1ic_addr	0088H		/* dma1 Interrupt Control Register */
#pragma ADDRESS     bcn1ic_addr	0089H		/* bus collision (uart1) interrput Control Register */
#pragma ADDRESS     bcn4ic_addr	0089H		/* bus collision (uart4) interrput Control Register */
#pragma ADDRESS     dm3ic_addr	008AH		/* dma3 Interrupt Control Register */
#pragma ADDRESS     kupic_addr	008BH		/* key input interrput Control Register */
#pragma ADDRESS     ta1ic_addr	008CH		/* timer a1 Interrupt Control Register */
#pragma ADDRESS     iio1ic_addr	008DH		/* iio1 Interrupt Control Register */
#pragma ADDRESS     ta3ic_addr	008EH		/* timer a3 Interrupt Control Register */
#pragma ADDRESS     iio3ic_addr	008FH		/* iio3 Interrupt Control Register */
#pragma ADDRESS     s0tic_addr	0090H		/* uart0 transmit interrput Control Register */
#pragma ADDRESS     iio5ic_addr	0091H		/* iio5 Interrupt Control Register */
#pragma ADDRESS     s1tic_addr	0092H		/* uart1 transmit interrput Control Register */
#pragma ADDRESS     iio7ic_addr	0093H		/* iio7 Interrupt Control Register */
#pragma ADDRESS     tb0ic_addr	0094H		/* timer b0 interrput Control Register */
#pragma ADDRESS     iio9ic_addr	0095H		/* iio9 Interrupt Control Register */
#pragma ADDRESS     tb2ic_addr	0096H		/* timer b2 interrput Control Register */
#pragma ADDRESS     iio11ic_addr	0097H		/* iio11 Interrupt Control Register */
#pragma ADDRESS     tb4ic_addr	0098H		/* timer b4 interrput Control Register */
#pragma ADDRESS     int4ic_addr	009AH		/* int4 interrput Control Register */
#pragma ADDRESS     int2ic_addr	009CH		/* int2 interrput Control Register */
#pragma ADDRESS     int0ic_addr	009EH		/* int0 interrput Control Register */
#pragma ADDRESS     iio0ir_addr	00A0H		/* Interruption requirement Register 0 */
#pragma ADDRESS     iio1ir_addr	00A1H		/* Interruption requirement Register 1 */
#pragma ADDRESS     iio2ir_addr	00A2H		/* Interruption requirement Register 2 */
#pragma ADDRESS     iio3ir_addr	00A3H		/* Interruption requirement Register 3 */
#pragma ADDRESS     iio4ir_addr	00A4H		/* Interruption requirement Register 4 */
#pragma ADDRESS     iio5ir_addr	00A5H		/* Interruption requirement Register 5 */
#pragma ADDRESS     iio6ir_addr	00A6H		/* Interruption requirement Register 6 */
#pragma ADDRESS     iio7ir_addr	00A7H		/* Interruption requirement Register 7 */
#pragma ADDRESS     iio8ir_addr	00A8H		/* Interruption requirement Register 8 */
#pragma ADDRESS     iio9ir_addr	00A9H		/* Interruption requirement Register 9 */
#pragma ADDRESS     iio10ir_addr	00AAH		/* Interruption requirement Register 10 */
#pragma ADDRESS     iio11ir_addr	00ABH		/* Interruption requirement Register 11 */
#pragma ADDRESS     iio0ie_addr	00B0H		/* Interruption permission Register 0 */
#pragma ADDRESS     iio1ie_addr	00B1H		/* Interruption permission Register 1 */
#pragma ADDRESS     iio2ie_addr	00B2H		/* Interruption permission Register 2 */
#pragma ADDRESS     iio3ie_addr	00B3H		/* Interruption permission Register 3 */
#pragma ADDRESS     iio4ie_addr	00B4H		/* Interruption permission Register 4 */
#pragma ADDRESS     iio5ie_addr	00B5H		/* Interruption permission Register 5 */
#pragma ADDRESS     iio6ie_addr	00B6H		/* Interruption permission Register 6 */
#pragma ADDRESS     iio7ie_addr	00B7H		/* Interruption permission Register 7 */
#pragma ADDRESS     iio8ie_addr	00B8H		/* Interruption permission Register 8 */
#pragma ADDRESS     iio9ie_addr	00B9H		/* Interruption permission Register 9 */
#pragma ADDRESS     iio10ie_addr	00BAH		/* Interruption permission Register 10 */
#pragma ADDRESS     iio11ie_addr	00BBH		/* Interruption permission Register 11 */
#pragma ADDRESS     s7tic_addr	00DDH		/* uart7 transmit/nack Interrupt Control Register */
#pragma ADDRESS     s8tic_addr	00DFH		/* uart8 transmit/nack Interrupt Control Register */
#pragma ADDRESS     s7ric_addr	00FDH		/* uart7 receive/ack Interrupt Control Register */
#pragma ADDRESS     s8ric_addr	00FFH		/* uart8 receive/ack Interrupt Control Register */
#pragma ADDRESS     g1tm0_addr	0100H		/* group1 time measurement Register 0 */
#pragma ADDRESS     g1po0_addr	0100H		/* group1 pulse output Register 0 */
#pragma ADDRESS     g1tm1_addr	0102H		/* group1 time measurement Register 1 */
#pragma ADDRESS     g1po1_addr	0102H		/* group1 pulse output Register 1 */
#pragma ADDRESS     g1tm2_addr	0104H		/* group1 time measurement Register 2 */
#pragma ADDRESS     g1po2_addr	0104H		/* group1 pulse output Register 2 */
#pragma ADDRESS     g1tm3_addr	0106H		/* group1 time measurement Register 3 */
#pragma ADDRESS     g1po3_addr	0106H		/* group1 pulse output Register 3 */
#pragma ADDRESS     g1tm4_addr	0108H		/* group1 time measurement Register 4 */
#pragma ADDRESS     g1po4_addr	0108H		/* group1 pulse output Register 4 */
#pragma ADDRESS     g1tm5_addr	010AH		/* group1 time measurement Register 5 */
#pragma ADDRESS     g1po5_addr	010AH		/* group1 pulse output Register 5 */
#pragma ADDRESS     g1tm6_addr	010CH		/* group1 time measurement Register 6 */
#pragma ADDRESS     g1po6_addr	010CH		/* group1 pulse output Register 6 */
#pragma ADDRESS     g1tm7_addr	010EH		/* group1 time measurement Register 7 */
#pragma ADDRESS     g1po7_addr	010EH		/* group1 pulse output Register 7 */
#pragma ADDRESS     g1pocr0_addr	0110H		/* group1 pulse output Control Register 0 */
#pragma ADDRESS     g1pocr1_addr	0111H		/* group1 pulse output Control Register 1 */
#pragma ADDRESS     g1pocr2_addr	0112H		/* group1 pulse output Control Register 2 */
#pragma ADDRESS     g1pocr3_addr	0113H		/* group1 pulse output Control Register 3 */
#pragma ADDRESS     g1pocr4_addr	0114H		/* group1 pulse output Control Register 4 */
#pragma ADDRESS     g1pocr5_addr	0115H		/* group1 pulse output Control Register 5 */
#pragma ADDRESS     g1pocr6_addr	0116H		/* group1 pulse output Control Register 6 */
#pragma ADDRESS     g1pocr7_addr	0117H		/* group1 pulse output Control Register 7 */
#pragma ADDRESS     g1tmcr0_addr	0118H		/* group1 time measurement Control Register 0 */
#pragma ADDRESS     g1tmcr1_addr	0119H		/* group1 time measurement Control Register 1 */
#pragma ADDRESS     g1tmcr2_addr	011AH		/* group1 time measurement Control Register 2 */
#pragma ADDRESS     g1tmcr3_addr	011BH		/* group1 time measurement Control Register 3 */
#pragma ADDRESS     g1tmcr4_addr	011CH		/* group1 time measurement Control Register 4 */
#pragma ADDRESS     g1tmcr5_addr	011DH		/* group1 time measurement Control Register 5 */
#pragma ADDRESS     g1tmcr6_addr	011EH		/* group1 time measurement Control Register 6 */
#pragma ADDRESS     g1tmcr7_addr	011FH		/* group1 time measurement Control Register 7 */
#pragma ADDRESS     g1bt_addr	0120H		/* group1 base timer Register */
#pragma ADDRESS     g1bcr0_addr	0122H		/* group1 base timer Control Register 0 */
#pragma ADDRESS     g1bcr1_addr	0123H		/* group1 base timer Control Register 1 */
#pragma ADDRESS     g1tpr6_addr	0124H		/* group1 priscale reload Register 6 */
#pragma ADDRESS     g1tpr7_addr	0125H		/* group1 priscale reload Register 7 */
#pragma ADDRESS     g1fe_addr	0126H		/* group1 function enable Register */
#pragma ADDRESS     g1fs_addr	0127H		/* group1 function select Register */
#pragma ADDRESS     g2po0_addr	0140H		/* group2 pulse output Register 0 */
#pragma ADDRESS     g2po1_addr	0142H		/* group2 pulse output Register 1 */
#pragma ADDRESS     g2po2_addr	0144H		/* group2 pulse output Register 2 */
#pragma ADDRESS     g2po3_addr	0146H		/* group2 pulse output Register 3 */
#pragma ADDRESS     g2po4_addr	0148H		/* group2 pulse output Register 4 */
#pragma ADDRESS     g2po5_addr	014AH		/* group2 pulse output Register 5 */
#pragma ADDRESS     g2po6_addr	014CH		/* group2 pulse output Register 6 */
#pragma ADDRESS     g2po7_addr	014EH		/* group2 pulse output Register 7 */
#pragma ADDRESS     g2pocr0_addr	0150H		/* group2 pulse output Control Register 0 */
#pragma ADDRESS     g2pocr1_addr	0151H		/* group2 pulse output Control Register 1 */
#pragma ADDRESS     g2pocr2_addr	0152H		/* group2 pulse output Control Register 2 */
#pragma ADDRESS     g2pocr3_addr	0153H		/* group2 pulse output Control Register 3 */
#pragma ADDRESS     g2pocr4_addr	0154H		/* group2 pulse output Control Register 4 */
#pragma ADDRESS     g2pocr5_addr	0155H		/* group2 pulse output Control Register 5 */
#pragma ADDRESS     g2pocr6_addr	0156H		/* group2 pulse output Control Register 6 */
#pragma ADDRESS     g2pocr7_addr	0157H		/* group2 pulse output Control Register 7 */
#pragma ADDRESS     g2bt_addr	0160H		/* group2 base timer Register */
#pragma ADDRESS     g2bcr0_addr	0162H		/* group2 base timer Control Register 0 */
#pragma ADDRESS     g2bcr1_addr	0163H		/* group2 base timer Control Register 1 */
#pragma ADDRESS     btsr_addr	0164H		/* Base timer Start Register */
#pragma ADDRESS     g2fe_addr	0166H		/* group2 function enable Register */
#pragma ADDRESS     g2rtp_addr	0167H		/* group2 RTP Output Buffer Register */
#pragma ADDRESS     g2mr_addr	016AH		/* group2 SI/O Transmit Receive Mode Register */
#pragma ADDRESS     g2cr_addr	016BH		/* group2 SI/O Transmit Receive Control Register */
#pragma ADDRESS     g2tb_addr	016CH		/* group2 SI/O Transmit Buffer Register */
#pragma ADDRESS     g2rb_addr	016EH		/* group2 SI/O Receive Buffer Register */
#pragma ADDRESS     iear_addr	0170H		/* group2 IEBus Address Register */
#pragma ADDRESS     iecr_addr	0172H		/* group2 IEBus Control Register */
#pragma ADDRESS     ietif_addr	0173H		/* group2 IEBus Transmit Interrupt Requiremet Register */
#pragma ADDRESS     ierif_addr	0174H		/* group2 IEBus Receive Interrupt Requiremet Register */
#pragma ADDRESS     g0tm0_addr	0180H		/* group0 time measurement Register 0 */
#pragma ADDRESS     g0po0_addr	0180H		/* group0 pulse output Register 0 */
#pragma ADDRESS     g0tm1_addr	0182H		/* group0 time measurement Register 1 */
#pragma ADDRESS     g0po1_addr	0182H		/* group0 pulse output Register 1 */
#pragma ADDRESS     g0tm2_addr	0184H		/* group0 time measurement Register 2 */
#pragma ADDRESS     g0po2_addr	0184H		/* group0 pulse output Register 2 */
#pragma ADDRESS     g0tm3_addr	0186H		/* group0 time measurement Register 3 */
#pragma ADDRESS     g0po3_addr	0186H		/* group0 pulse output Register 3 */
#pragma ADDRESS     g0tm4_addr	0188H		/* group0 time measurement Register 4 */
#pragma ADDRESS     g0po4_addr	0188H		/* group0 pulse output Register 4 */
#pragma ADDRESS     g0tm5_addr	018AH		/* group0 time measurement Register 5 */
#pragma ADDRESS     g0po5_addr	018AH		/* group0 pulse output Register 5 */
#pragma ADDRESS     g0tm6_addr	018CH		/* group0 time measurement Register 6 */
#pragma ADDRESS     g0po6_addr	018CH		/* group0 pulse output Register 6 */
#pragma ADDRESS     g0tm7_addr	018EH		/* group0 time measurement Register 7 */
#pragma ADDRESS     g0po7_addr	018EH		/* group0 pulse output Register 7 */
#pragma ADDRESS     g0pocr0_addr	0190H		/* group0 pulse output Control Register 0 */
#pragma ADDRESS     g0pocr1_addr	0191H		/* group0 pulse output Control Register 1 */
#pragma ADDRESS     g0pocr2_addr	0192H		/* group0 pulse output Control Register 2 */
#pragma ADDRESS     g0pocr3_addr	0193H		/* group0 pulse output Control Register 3 */
#pragma ADDRESS     g0pocr4_addr	0194H		/* group0 pulse output Control Register 4 */
#pragma ADDRESS     g0pocr5_addr	0195H		/* group0 pulse output Control Register 5 */
#pragma ADDRESS     g0pocr6_addr	0196H		/* group0 pulse output Control Register 6 */
#pragma ADDRESS     g0pocr7_addr	0197H		/* group0 pulse output Control Register 7 */
#pragma ADDRESS     g0tmcr0_addr	0198H		/* group0 time measurement Control Register 0 */
#pragma ADDRESS     g0tmcr1_addr	0199H		/* group0 time measurement Control Register 1 */
#pragma ADDRESS     g0tmcr2_addr	019AH		/* group0 time measurement Control Register 2 */
#pragma ADDRESS     g0tmcr3_addr	019BH		/* group0 time measurement Control Register 3 */
#pragma ADDRESS     g0tmcr4_addr	019CH		/* group0 time measurement Control Register 4 */
#pragma ADDRESS     g0tmcr5_addr	019DH		/* group0 time measurement Control Register 5 */
#pragma ADDRESS     g0tmcr6_addr	019EH		/* group0 time measurement Control Register 6 */
#pragma ADDRESS     g0tmcr7_addr	019FH		/* group0 time measurement Control Register 7 */
#pragma ADDRESS     g0bt_addr	01A0H		/* group0 base timer Register */
#pragma ADDRESS     g0bcr0_addr	01A2H		/* group0 base timer Control Register 0 */
#pragma ADDRESS     g0bcr1_addr	01A3H		/* group0 base timer Control Register 1 */
#pragma ADDRESS     g0tpr6_addr	01A4H		/* group0 priscale reload Register 6 */
#pragma ADDRESS     g0tpr7_addr	01A5H		/* group0 priscale reload Register 7 */
#pragma ADDRESS     g0fe_addr	01A6H		/* group0 function enable Register */
#pragma ADDRESS     g0fs_addr	01A7H		/* group0 function select Register */
#pragma ADDRESS     u5smr4_addr	01C4H		/* uart5 special mode Register 4 */
#pragma ADDRESS     u5smr3_addr	01C5H		/* uart5 special mode Register 3 */
#pragma ADDRESS     u5smr2_addr	01C6H		/* uart5 special mode Register 2 */
#pragma ADDRESS     u5smr_addr	01C7H		/* uart5 special mode Register */
#pragma ADDRESS     u5mr_addr	01C8H		/* uart5 transmit receive mode Register */
#pragma ADDRESS     u5brg_addr	01C9H		/* uart5 bit rate generator */
#pragma ADDRESS     u5tb_addr	01CAH		/* uart5 transmit buffer Register */
#pragma ADDRESS     u5c0_addr	01CCH		/* uart5 transmit receive Control Register 0 */
#pragma ADDRESS     u5c1_addr	01CDH		/* uart5 transmit receive Control Register 1 */
#pragma ADDRESS     u5rb_addr	01CEH		/* uart5 receive buffer Register */
#pragma ADDRESS     u6smr4_addr	01D4H		/* uart6 special mode Register 4 */
#pragma ADDRESS     u6smr3_addr	01D5H		/* uart6 special mode Register 3 */
#pragma ADDRESS     u6smr2_addr	01D6H		/* uart6 special mode Register 2 */
#pragma ADDRESS     u6smr_addr	01D7H		/* uart6 special mode Register */
#pragma ADDRESS     u6mr_addr	01D8H		/* uart6 transmit receive mode Register */
#pragma ADDRESS     u6brg_addr	01D9H		/* uart6 bit rate generator */
#pragma ADDRESS     u6tb_addr	01DAH		/* uart6 transmit buffer Register */
#pragma ADDRESS     u6c0_addr	01DCH		/* uart6 transmit receive Control Register 0 */
#pragma ADDRESS     u6c1_addr	01DDH		/* uart6 transmit receive Control Register 1 */
#pragma ADDRESS     u6rb_addr	01DEH		/* uart6 receive buffer Register */
#pragma ADDRESS     u7mr_addr	01E0H		/* uart7 transmit receive mode Register */
#pragma ADDRESS     u7brg_addr	01E1H		/* uart7 bit rate generator */
#pragma ADDRESS     u7tb_addr	01E2H		/* uart7 transmit buffer Register */
#pragma ADDRESS     u7c0_addr	01E4H		/* uart7 transmit receive Control Register 0 */
#pragma ADDRESS     u7c1_addr	01E5H		/* uart7 transmit receive Control Register 1 */
#pragma ADDRESS     u7rb_addr	01E6H		/* uart7 receive buffer Register */
#pragma ADDRESS     u8mr_addr	01E8H		/* uart8 transmit receive mode Register */
#pragma ADDRESS     u8brg_addr	01E9H		/* uart8 bit rate generator */
#pragma ADDRESS     u8tb_addr	01EAH		/* uart8 transmit buffer Register */
#pragma ADDRESS     u8c0_addr	01ECH		/* uart8 transmit receive Control Register 0 */
#pragma ADDRESS     u8c1_addr	01EDH		/* uart8 transmit receive Control Register 1 */
#pragma ADDRESS     u8rb_addr	01EEH		/* uart8 receive buffer Register */
#pragma ADDRESS     u78con_addr	01F0H		/* uart7,8 transmit receive Control Register 2 */
#pragma ADDRESS     x0r_addr	02C0H		/* x0 Register */
#pragma ADDRESS     y0r_addr	02C0H		/* y0 Register */
#pragma ADDRESS     x1r_addr	02C2H		/* x1 Register */
#pragma ADDRESS     y1r_addr	02C2H		/* y1 Register */
#pragma ADDRESS     x2r_addr	02C4H		/* x2 Register */
#pragma ADDRESS     y2r_addr	02C4H		/* y2 Register */
#pragma ADDRESS     x3r_addr	02C6H		/* x3 Register */
#pragma ADDRESS     y3r_addr	02C6H		/* y3 Register */
#pragma ADDRESS     x4r_addr	02C8H		/* x4 Register */
#pragma ADDRESS     y4r_addr	02C8H		/* y4 Register */
#pragma ADDRESS     x5r_addr	02CAH		/* x5 Register */
#pragma ADDRESS     y5r_addr	02CAH		/* y5 Register */
#pragma ADDRESS     x6r_addr	02CCH		/* x6 Register */
#pragma ADDRESS     y6r_addr	02CCH		/* y6 Register */
#pragma ADDRESS     x7r_addr	02CEH		/* x7 Register */
#pragma ADDRESS     y7r_addr	02CEH		/* y7 Register */
#pragma ADDRESS     x8r_addr	02D0H		/* x8 Register */
#pragma ADDRESS     y8r_addr	02D0H		/* y8 Register */
#pragma ADDRESS     x9r_addr	02D2H		/* x9 Register */
#pragma ADDRESS     y9r_addr	02D2H		/* y9 Register */
#pragma ADDRESS     x10r_addr	02D4H		/* x10 Register */
#pragma ADDRESS     y10r_addr	02D4H		/* y10 Register */
#pragma ADDRESS     x11r_addr	02D6H		/* x11 Register */
#pragma ADDRESS     y11r_addr	02D6H		/* y11 Register */
#pragma ADDRESS     x12r_addr	02D8H		/* x12 Register */
#pragma ADDRESS     y12r_addr	02D8H		/* y12 Register */
#pragma ADDRESS     x13r_addr	02DAH		/* x13 Register */
#pragma ADDRESS     y13r_addr	02DAH		/* y13 Register */
#pragma ADDRESS     x14r_addr	02DCH		/* x14 Register */
#pragma ADDRESS     y14r_addr	02DCH		/* y14 Register */
#pragma ADDRESS     x15r_addr	02DEH		/* x15 Register */
#pragma ADDRESS     y15r_addr	02DEH		/* y15 Register */
#pragma ADDRESS     xyc_addr	02E0H		/* x-y Control Register */
#pragma ADDRESS     u1smr4_addr	02E4H		/* uart1 special mode Register 4 */
#pragma ADDRESS     u1smr3_addr	02E5H		/* uart1 special mode Register 3 */
#pragma ADDRESS     u1smr2_addr	02E6H		/* uart1 special mode Register 2 */
#pragma ADDRESS     u1smr_addr	02E7H		/* uart1 special mode Register */
#pragma ADDRESS     u1mr_addr	02E8H		/* uart1 transmit receive mode Register */
#pragma ADDRESS     u1brg_addr	02E9H		/* uart1 bit rate generator */
#pragma ADDRESS     u1tb_addr	02EAH		/* uart1 transmit buffer Register */
#pragma ADDRESS     u1c0_addr	02ECH		/* uart1 transmit receive Control Register 0 */
#pragma ADDRESS     u1c1_addr	02EDH		/* uart1 transmit receive Control Register 1 */
#pragma ADDRESS     u1rb_addr	02EEH		/* uart1 receive buffer Register */
#pragma ADDRESS     u4smr4_addr	02F4H		/* uart4 special mode Register 4 */
#pragma ADDRESS     u4smr3_addr	02F5H		/* uart4 special mode Register 3 */
#pragma ADDRESS     u4smr2_addr	02F6H		/* uart4 special mode Register 2 */
#pragma ADDRESS     u4smr_addr	02F7H		/* uart4 special mode Register */
#pragma ADDRESS     u4mr_addr	02F8H		/* uart4 transmit receive mode Register */
#pragma ADDRESS     u4brg_addr	02F9H		/* uart4 bit rate generator */
#pragma ADDRESS     u4tb_addr	02FAH		/* uart4 transmit buffer Register */
#pragma ADDRESS     u4c0_addr	02FCH		/* uart4 transmit receive Control Register 0 */
#pragma ADDRESS     u4c1_addr	02FDH		/* uart4 transmit receive Control Register 1 */
#pragma ADDRESS     u4rb_addr	02FEH		/* uart4 receive buffer Register */
#pragma ADDRESS     tbsr_addr	0300H		/* timer b3,4,5 count start flag */
#pragma ADDRESS     ta11_addr	0302H		/* timer a1-1 Register */
#pragma ADDRESS     ta21_addr	0304H		/* timer a2-1 Register */
#pragma ADDRESS     ta41_addr	0306H		/* timer a4-1 Register */
#pragma ADDRESS     invc0_addr	0308H		/* three phase pwm Control Register 0 */
#pragma ADDRESS     invc1_addr	0309H		/* three phase pwm Control Register 1 */
#pragma ADDRESS     idb0_addr	030AH		/* three phase output buffer Register 0 */
#pragma ADDRESS     idb1_addr	030BH		/* three phase output buffer Register 1 */
#pragma ADDRESS     dtt_addr	030CH		/* dead time timer */
#pragma ADDRESS     ictb2_addr	030DH		/* 	timer b2 Interrupt occurrence frequency set counter */
#pragma ADDRESS     tb3_addr	0310H		/* timer b3 Register */
#pragma ADDRESS     tb4_addr	0312H		/* timer b4 Register */
#pragma ADDRESS     tb5_addr	0314H		/* timer 55 Register */
#pragma ADDRESS     tb3mr_addr	031BH		/* timer b3 mode Register */
#pragma ADDRESS     tb4mr_addr	031CH		/* timer b4 mode Register */
#pragma ADDRESS     tb5mr_addr	031DH		/* timer b5 mode Register */
#pragma ADDRESS     u3smr4_addr	0324H		/* uart3 special mode Register 4 */
#pragma ADDRESS     u3smr3_addr	0325H		/* uart3 special mode Register 3 */
#pragma ADDRESS     u3smr2_addr	0326H		/* uart3 special mode Register 2 */
#pragma ADDRESS     u3smr_addr	0327H		/* uart3 special mode Register */
#pragma ADDRESS     u3mr_addr	0328H		/* uart3 transmit receive mode Register */
#pragma ADDRESS     u3brg_addr	0329H		/* uart3 bit rate generator */
#pragma ADDRESS     u3tb_addr	032AH		/* uart3 transmit buffer Register */
#pragma ADDRESS     u3c0_addr	032CH		/* uart3 transmit receive Control Register 0 */
#pragma ADDRESS     u3c1_addr	032DH		/* uart3 transmit receive Control Register 1 */
#pragma ADDRESS     u3rb_addr	032EH		/* uart3 receive buffer Register */
#pragma ADDRESS     u2smr4_addr	0334H		/* uart2 special mode Register 4 */
#pragma ADDRESS     u2smr3_addr	0335H		/* uart2 special mode Register 3 */
#pragma ADDRESS     u2smr2_addr	0336H		/* uart2 special mode Register 2 */
#pragma ADDRESS     u2smr_addr	0337H		/* uart2 special mode Register */
#pragma ADDRESS     u2mr_addr	0338H		/* uart2 transmit receive mode Register */
#pragma ADDRESS     u2brg_addr	0339H		/* uart2 bit rate generator */
#pragma ADDRESS     u2tb_addr	033AH		/* uart2 transmit buffer Register */
#pragma ADDRESS     u2c0_addr	033CH		/* uart2 transmit receive Control Register 0 */
#pragma ADDRESS     u2c1_addr	033DH		/* uart2 transmit receive Control Register 1 */
#pragma ADDRESS     u2rb_addr	033EH		/* uart2 receive buffer Register */
#pragma ADDRESS     tabsr_addr	0340H		/* count start flag */
#pragma ADDRESS     cpsrf_addr	0341H		/* clock prescaler reset flag */
#pragma ADDRESS     onsf_addr	0342H		/* one shot start flag */
#pragma ADDRESS     trgsr_addr	0343H		/* trigger select Register */
#pragma ADDRESS     udf_addr	0344H		/* up down flag */
#pragma ADDRESS     ta0_addr	0346H		/* timer a0 */
#pragma ADDRESS     ta1_addr	0348H		/* timer a1 */
#pragma ADDRESS     ta2_addr	034AH		/* timer a2 */
#pragma ADDRESS     ta3_addr	034CH		/* timer a3 */
#pragma ADDRESS     ta4_addr	034EH		/* timer a4 */
#pragma ADDRESS     tb0_addr	0350H		/* timer b0 */
#pragma ADDRESS     tb1_addr	0352H		/* timer b1 */
#pragma ADDRESS     tb2_addr	0354H		/* timer b2 */
#pragma ADDRESS     ta0mr_addr	0356H		/* timer a0 mode Register */
#pragma ADDRESS     ta1mr_addr	0357H		/* timer a1 mode Register */
#pragma ADDRESS     ta2mr_addr	0358H		/* timer a2 mode Register */
#pragma ADDRESS     ta3mr_addr	0359H		/* timer a3 mode Register */
#pragma ADDRESS     ta4mr_addr	035AH		/* timer a4 mode Register */
#pragma ADDRESS     tb0mr_addr	035BH		/* timer b0 mode Register */
#pragma ADDRESS     tb1mr_addr	035CH		/* timer b1 mode Register */
#pragma ADDRESS     tb2mr_addr	035DH		/* timer b2 mode Register */
#pragma ADDRESS     tb2sc_addr	035EH		/* timer b2 special mode Register */
#pragma ADDRESS     tcspr_addr	035FH		/* timer count source prescaler Register */
#pragma ADDRESS     u0smr4_addr	0364H		/* uart0 special mode Register 4 */
#pragma ADDRESS     u0smr3_addr	0365H		/* uart0 special mode Register 3 */
#pragma ADDRESS     u0smr2_addr	0366H		/* uart0 special mode Register 2 */
#pragma ADDRESS     u0smr_addr	0367H		/* uart0 special mode Register */
#pragma ADDRESS     u0mr_addr	0368H		/* uart0 transmit receive mode Register */
#pragma ADDRESS     u0brg_addr	0369H		/* uart0 bit rate generator */
#pragma ADDRESS     u0tb_addr	036AH		/* uart0 transmit buffer Register */
#pragma ADDRESS     u0c0_addr	036CH		/* uart0 transmit receive Control Register 0 */
#pragma ADDRESS     u0c1_addr	036DH		/* uart0 transmit receive Control Register 1 */
#pragma ADDRESS     u0rb_addr	036EH		/* uart0 receive buffer Register */
#pragma ADDRESS     crcd_addr	037CH		/* crc data Register */
#pragma ADDRESS     crcin_addr	037EH		/* crc input Register */
#pragma ADDRESS     ad00_addr	0380H		/* a-d0 Register 0 */
#pragma ADDRESS     ad01_addr	0382H		/* a-d0 Register 1 */
#pragma ADDRESS     ad02_addr	0384H		/* a-d0 Register 2 */
#pragma ADDRESS     ad03_addr	0386H		/* a-d0 Register 3 */
#pragma ADDRESS     ad04_addr	0388H		/* a-d0 Register 4 */
#pragma ADDRESS     ad05_addr	038AH		/* a-d0 Register 5 */
#pragma ADDRESS     ad06_addr	038CH		/* a-d0 Register 6 */
#pragma ADDRESS     ad07_addr	038EH		/* a-d0 Register 7 */
#pragma ADDRESS     ad0con4_addr	0392H		/* a-d0 Control Register 4 */
#pragma ADDRESS     ad0con2_addr	0394H		/* a-d0 Control Register 2 */
#pragma ADDRESS     ad0con3_addr	0395H		/* a-d0 Control Register 3 */
#pragma ADDRESS     ad0con0_addr	0396H		/* a-d0 Control Register 0 */
#pragma ADDRESS     ad0con1_addr	0397H		/* a-d0 Control Register 1 */
#pragma ADDRESS     da0_addr	0398H		/* d-a Register 0 */
#pragma ADDRESS     da1_addr	039AH		/* d-a Register 1 */
#pragma ADDRESS     dacon_addr	039CH		/* d-a Control Register */
#pragma ADDRESS     p0_addr	03C0H		/* port p0 Register */
#pragma ADDRESS     p1_addr	03C1H		/* port p1 Register */
#pragma ADDRESS     pd0_addr	03C2H		/* port p0 direction Register */
#pragma ADDRESS     pd1_addr	03C3H		/* port p1 direction Register */
#pragma ADDRESS     p2_addr	03C4H		/* port p2 Register */
#pragma ADDRESS     p3_addr	03C5H		/* port p3 Register */
#pragma ADDRESS     pd2_addr	03C6H		/* port p2 direction Register */
#pragma ADDRESS     pd3_addr	03C7H		/* port p3 direction Register */
#pragma ADDRESS     p4_addr	03C8H		/* port p4 Register */
#pragma ADDRESS     p5_addr	03C9H		/* port p5 Register */
#pragma ADDRESS     pd4_addr	03CAH		/* port p4 direction Register */
#pragma ADDRESS     pd5_addr	03CBH		/* port p5 direction Register */
#pragma ADDRESS     p6_addr	03CCH		/* port p6 Register */
#pragma ADDRESS     p7_addr	03CDH		/* port p7 Register */
#pragma ADDRESS     pd6_addr	03CEH		/* port p6 direction Register */
#pragma ADDRESS     pd7_addr	03CFH		/* port p7 direction Register */
#pragma ADDRESS     p8_addr	03D0H		/* port p8 Register */
#pragma ADDRESS     p9_addr	03D1H		/* port p9 Register */
#pragma ADDRESS     pd8_addr	03D2H		/* port p8 direction Register */
#pragma ADDRESS     pd9_addr	03D3H		/* port p9 direction Register */
#pragma ADDRESS     p10_addr	03D4H		/* port p10 Register */
#pragma ADDRESS     pd10_addr	03D6H		/* port p10 direction Register */
#pragma ADDRESS     pur0_addr	03F0H		/* pull-up Control Register 0 */
#pragma ADDRESS     pur1_addr	03F1H		/* pull-up Control Register 1 */
#pragma ADDRESS     pur2_addr	03F2H		/* pull-up Control Register 2 */
#pragma ADDRESS     pur3_addr	03F3H		/* pull-up Control Register 3 */
#pragma ADDRESS     pcr_addr	03FFH		/* port Control Register */
#pragma ADDRESS     fmr0_addr	040000H		/* Flash Memory Control Register 0 */
#pragma ADDRESS     fmsr0_addr	040001H		/* Flash Memory Starus Register	0 */
#pragma ADDRESS     fpr0_addr	040008H		/* Flash Register Protect Cancel Register	0 */
#pragma ADDRESS     fmr1_addr	040009H		/* Flash Memory Control Register 1 */
#pragma ADDRESS     fbpm0_addr	04000AH		/* Flash Memory Protect Bit Moniter Register 0 */
#pragma ADDRESS     fbpm1_addr	04000BH		/* Flash Memory Protect Bit Moniter Register 1 */
#pragma ADDRESS     plc0_addr	040020H		/* PLL Control Register 0 */
#pragma ADDRESS     plc1_addr	040021H		/* PLL Control Register 1 */
#pragma ADDRESS     pm0_addr	040044H		/* Processer Mode Register */
#pragma ADDRESS     cm0_addr	040046H		/* Systen Clock Control Register 0 */
#pragma ADDRESS     cm1_addr	040047H		/* Systen Clock Control Register 1 */
#pragma ADDRESS     pm3_addr	040048H		/* Processer Mode Register	3 */
#pragma ADDRESS     prcr_addr	04004AH		/* Protect Register */
#pragma ADDRESS     prcr3_addr	04004CH		/* Protect Register 3 */
#pragma ADDRESS     cm2_addr	04004DH		/* Systen Clock Control Register 2 */
#pragma ADDRESS     pm2_addr	040053H		/* Processer Mode Register	2 */
#pragma ADDRESS     csop0_addr	040054H		/* CS Output Pin Setting Register 0 */
#pragma ADDRESS     csop1_addr	040055H		/* CS Output Pin Setting Register 1 */
#pragma ADDRESS     cm3_addr	04005AH		/* Slow Speed Mode Clock Control Register */
#pragma ADDRESS     vrcr_addr	040060H		/* Voltage Regulater Control Register */
#pragma ADDRESS     lvdc_addr	040062H		/* Voltage Down Detection Circuit Control Register */
#pragma ADDRESS     dvcr_addr	040064H		/* Detection Voltage Setting Register */
#pragma ADDRESS     iobc_addr	040097H		/* three phase output buffer Control Register */
#pragma ADDRESS     ifs0_addr	040098H		/* Input function select Register 0 */
#pragma ADDRESS     ifs2_addr	04009AH		/* Input function select Register 2 */
#pragma ADDRESS     ifs3_addr	04009BH		/* Input function select Register 3 */
#pragma ADDRESS     p0_0s_addr	0400A0H		/* Port P0_0 Function Select Register */
#pragma ADDRESS     p1_0s_addr	0400A1H		/* Port P1_0 Function Select Register */
#pragma ADDRESS     p0_1s_addr	0400A2H		/* Port P0_1 Function Select Register */
#pragma ADDRESS     p1_1s_addr	0400A3H		/* Port P1_1 Function Select Register */
#pragma ADDRESS     p0_2s_addr	0400A4H		/* Port P0_2 Function Select Register */
#pragma ADDRESS     p1_2s_addr	0400A5H		/* Port P1_2 Function Select Register */
#pragma ADDRESS     p0_3s_addr	0400A6H		/* Port P0_3 Function Select Register */
#pragma ADDRESS     p1_3s_addr	0400A7H		/* Port P1_3 Function Select Register */
#pragma ADDRESS     p0_4s_addr	0400A8H		/* Port P0_4 Function Select Register */
#pragma ADDRESS     p1_4s_addr	0400A9H		/* Port P1_4 Function Select Register */
#pragma ADDRESS     p0_5s_addr	0400AAH		/* Port P0_5 Function Select Register */
#pragma ADDRESS     p1_5s_addr	0400ABH		/* Port P1_5 Function Select Register */
#pragma ADDRESS     p0_6s_addr	0400ACH		/* Port P0_6 Function Select Register */
#pragma ADDRESS     p1_6s_addr	0400ADH		/* Port P1_6 Function Select Register */
#pragma ADDRESS     p0_7s_addr	0400AEH		/* Port P0_7 Function Select Register */
#pragma ADDRESS     p1_7s_addr	0400AFH		/* Port P1_7 Function Select Register */
#pragma ADDRESS     p2_0s_addr	0400B0H		/* Port P2_0 Function Select Register */
#pragma ADDRESS     p3_0s_addr	0400B1H		/* Port P3_0 Function Select Register */
#pragma ADDRESS     p2_1s_addr	0400B2H		/* Port P2_1 Function Select Register */
#pragma ADDRESS     p3_1s_addr	0400B3H		/* Port P3_1 Function Select Register */
#pragma ADDRESS     p2_2s_addr	0400B4H		/* Port P2_2 Function Select Register */
#pragma ADDRESS     p3_2s_addr	0400B5H		/* Port P3_2 Function Select Register */
#pragma ADDRESS     p2_3s_addr	0400B6H		/* Port P2_3 Function Select Register */
#pragma ADDRESS     p3_3s_addr	0400B7H		/* Port P3_3 Function Select Register */
#pragma ADDRESS     p2_4s_addr	0400B8H		/* Port P2_4 Function Select Register */
#pragma ADDRESS     p3_4s_addr	0400B9H		/* Port P3_4 Function Select Register */
#pragma ADDRESS     p2_5s_addr	0400BAH		/* Port P2_5 Function Select Register */
#pragma ADDRESS     p3_5s_addr	0400BBH		/* Port P3_5 Function Select Register */
#pragma ADDRESS     p2_6s_addr	0400BCH		/* Port P2_6 Function Select Register */
#pragma ADDRESS     p3_6s_addr	0400BDH		/* Port P3_6 Function Select Register */
#pragma ADDRESS     p2_7s_addr	0400BEH		/* Port P2_7 Function Select Register */
#pragma ADDRESS     p3_7s_addr	0400BFH		/* Port P3_7 Function Select Register */
#pragma ADDRESS     p4_0s_addr	0400C0H		/* Port P4_0 Function Select Register */
#pragma ADDRESS     p5_0s_addr	0400C1H		/* Port P5_0 Function Select Register */
#pragma ADDRESS     p4_1s_addr	0400C2H		/* Port P4_1 Function Select Register */
#pragma ADDRESS     p5_1s_addr	0400C3H		/* Port P5_1 Function Select Register */
#pragma ADDRESS     p4_2s_addr	0400C4H		/* Port P4_2 Function Select Register */
#pragma ADDRESS     p5_2s_addr	0400C5H		/* Port P5_2 Function Select Register */
#pragma ADDRESS     p4_3s_addr	0400C6H		/* Port P4_3 Function Select Register */
#pragma ADDRESS     p5_3s_addr	0400C7H		/* Port P5_3 Function Select Register */
#pragma ADDRESS     p4_4s_addr	0400C8H		/* Port P4_4 Function Select Register */
#pragma ADDRESS     p5_4s_addr	0400C9H		/* Port P5_4 Function Select Register */
#pragma ADDRESS     p4_5s_addr	0400CAH		/* Port P4_5 Function Select Register */
#pragma ADDRESS     p5_5s_addr	0400CBH		/* Port P5_5 Function Select Register */
#pragma ADDRESS     p4_6s_addr	0400CCH		/* Port P4_6 Function Select Register */
#pragma ADDRESS     p5_6s_addr	0400CDH		/* Port P5_6 Function Select Register */
#pragma ADDRESS     p4_7s_addr	0400CEH		/* Port P4_7 Function Select Register */
#pragma ADDRESS     p5_7s_addr	0400CFH		/* Port P5_7 Function Select Register */
#pragma ADDRESS     p6_0s_addr	0400D0H		/* Port P6_0 Function Select Register */
#pragma ADDRESS     p7_0s_addr	0400D1H		/* Port P7_0 Function Select Register */
#pragma ADDRESS     p6_1s_addr	0400D2H		/* Port P6_1 Function Select Register */
#pragma ADDRESS     p7_1s_addr	0400D3H		/* Port P7_1 Function Select Register */
#pragma ADDRESS     p6_2s_addr	0400D4H		/* Port P6_2 Function Select Register */
#pragma ADDRESS     p7_2s_addr	0400D5H		/* Port P7_2 Function Select Register */
#pragma ADDRESS     p6_3s_addr	0400D6H		/* Port P6_3 Function Select Register */
#pragma ADDRESS     p7_3s_addr	0400D7H		/* Port P7_3 Function Select Register */
#pragma ADDRESS     p6_4s_addr	0400D8H		/* Port P6_4 Function Select Register */
#pragma ADDRESS     p7_4s_addr	0400D9H		/* Port P7_4 Function Select Register */
#pragma ADDRESS     p6_5s_addr	0400DAH		/* Port P6_5 Function Select Register */
#pragma ADDRESS     p7_5s_addr	0400DBH		/* Port P7_5 Function Select Register */
#pragma ADDRESS     p6_6s_addr	0400DCH		/* Port P6_6 Function Select Register */
#pragma ADDRESS     p7_6s_addr	0400DDH		/* Port P7_6 Function Select Register */
#pragma ADDRESS     p6_7s_addr	0400DEH		/* Port P6_7 Function Select Register */
#pragma ADDRESS     p7_7s_addr	0400DFH		/* Port P7_7 Function Select Register */
#pragma ADDRESS     p8_0s_addr	0400E0H		/* Port P8_0 Function Select Register */
#pragma ADDRESS     p8_1s_addr	0400E2H		/* Port P8_1 Function Select Register */
#pragma ADDRESS     p8_2s_addr	0400E4H		/* Port P8_2 Function Select Register */
#pragma ADDRESS     p8_3s_addr	0400E6H		/* Port P8_3 Function Select Register */
#pragma ADDRESS     p9_3s_addr	0400E7H		/* Port P9_3 Function Select Register */
#pragma ADDRESS     p8_4s_addr	0400E8H		/* Port P8_4 Function Select Register */
#pragma ADDRESS     p9_4s_addr	0400E9H		/* Port P9_4 Function Select Register */
#pragma ADDRESS     p9_5s_addr	0400EBH		/* Port P9_5 Function Select Register */
#pragma ADDRESS     p8_6s_addr	0400ECH		/* Port P8_6 Function Select Register */
#pragma ADDRESS     p9_6s_addr	0400EDH		/* Port P9_6 Function Select Register */
#pragma ADDRESS     p8_7s_addr	0400EEH		/* Port P8_7 Function Select Register */
#pragma ADDRESS     p9_7s_addr	0400EFH		/* Port P9_7 Function Select Register */
#pragma ADDRESS     p10_0s_addr	0400F0H		/* Port P10_0 Function Select Register */
#pragma ADDRESS     p10_1s_addr	0400F2H		/* Port P10_1 Function Select Register */
#pragma ADDRESS     p10_2s_addr	0400F4H		/* Port P10_2 Function Select Register */
#pragma ADDRESS     p10_3s_addr	0400F6H		/* Port P10_3 Function Select Register */
#pragma ADDRESS     p10_4s_addr	0400F8H		/* Port P10_4 Function Select Register */
#pragma ADDRESS     p10_5s_addr	0400FAH		/* Port P10_5 Function Select Register */
#pragma ADDRESS     p10_6s_addr	0400FCH		/* Port P10_6 Function Select Register */
#pragma ADDRESS     p10_7s_addr	0400FEH		/* Port P10_7 Function Select Register */
#pragma ADDRESS     wdts_addr	04404EH		/* Watchdog Timer Register */
#pragma ADDRESS     wdc_addr	04404FH		/* Watchdog Timer Control Register */
#pragma ADDRESS		prcr2_addr	04405FH		/* Protect Register 2 */
#pragma ADDRESS     ifsr1_addr	04406DH		/* Interrupt cause select Register 1 */
#pragma ADDRESS     ifsr0_addr	04406FH		/* Interrupt cause select Register 0 */
#pragma ADDRESS     dm0sl2_addr	044070H		/* dma0 request cause select Register	2 */
#pragma ADDRESS     dm1sl2_addr	044071H		/* dma1 request cause select Register	2 */
#pragma ADDRESS     dm2sl2_addr	044072H		/* dma2 request cause select Register	2 */
#pragma ADDRESS     dm3sl2_addr	044073H		/* dma3 request cause select Register	2 */
#pragma ADDRESS     dm0sl_addr	044078H		/* dma0 request cause select Register */
#pragma ADDRESS     dm1sl_addr	044079H		/* dma1 request cause select Register */
#pragma ADDRESS     dm2sl_addr	04407AH		/* dma2 request cause select Register */
#pragma ADDRESS     dm3sl_addr	04407BH		/* dma3 request cause select Register */
#pragma ADDRESS     ripl2_addr	04407DH		/* Exit Priority Register 2 */
#pragma ADDRESS     ripl1_addr	04407FH		/* Exit Priority Register 1 */

/********************************************************
*   declare SFR bit                                     *
********************************************************/
struct bit_def {
        char    b0:1;
        char    b1:1;
        char    b2:1;
        char    b3:1;
        char    b4:1;
        char    b5:1;
        char    b6:1;
        char    b7:1;
};
union byte_def{
    struct bit_def bit;
    char    byte;
};

struct byte2_def {
		char	low;
		char	high;
};

struct bit2_def {
		char	b0:1;
		char	b1:1;
		char	b2:1;
		char	b3:1;
		char	b4:1;
		char	b5:1;
		char	b6:1;
		char	b7:1;
		char	b8:1;
		char	b9:1;
		char	b10:1;
		char	b11:1;
		char	b12:1;
		char	b13:1;
		char	b14:1;
		char	b15:1;
};

union word_def{
	struct bit2_def bit;
	struct byte2_def byte;
	short  word;
};
struct byte4_def {
		char	lowlow;
		char	lowhigh;
		char	highlow;
		char	highhigh;
};
struct word2_def {
		short	low;
		short	high;
};
struct bit4_def {
		char	b0:1;
		char	b1:1;
		char	b2:1;
		char	b3:1;
		char	b4:1;
		char	b5:1;
		char	b6:1;
		char	b7:1;
		char	b8:1;
		char	b9:1;
		char	b10:1;
		char	b11:1;
		char	b12:1;
		char	b13:1;
		char	b14:1;
		char	b15:1;
		char	b16:1;
		char	b17:1;
		char	b18:1;
		char	b19:1;
		char	b20:1;
		char	b21:1;
		char	b22:1;
		char	b23:1;
		char	b24:1;
		char	b25:1;
		char	b26:1;
		char	b27:1;
		char	b28:1;
		char	b29:1;
		char	b30:1;
		char	b31:1;
};
union lword_def{
	struct bit4_def bit;
	struct byte4_def byte;
	struct word2_def word;
	long lword;
};
/*------------------------------------------------------
    Clock Control Register
------------------------------------------------------*/
union byte_def ccr_addr;
#define     ccr     ccr_addr.byte

#define     bcd0		ccr_addr.bit.b0
#define     bcd1		ccr_addr.bit.b1
#define     ccd0		ccr_addr.bit.b2
#define     ccd1		ccr_addr.bit.b3
#define     pcd0		ccr_addr.bit.b4
#define     pcd1		ccr_addr.bit.b5
#define     bcs			ccr_addr.bit.b7

/*------------------------------------------------------
	Flash Memory Control Register
------------------------------------------------------*/
union byte_def fmcr_addr;
#define     fmcr     fmcr_addr.byte

#define     few			fmcr_addr.bit.b7

/*------------------------------------------------------
	Protect Register
------------------------------------------------------*/
union byte_def prr_addr;
#define     prr		prr_addr.byte

/*------------------------------------------------------
	Outer Bus Control Register 3
------------------------------------------------------*/
union word_def ebc3_addr;
#define		ebc3	ebc3_addr.word

#define		ebc3l	ebc3_addr.byte.low
#define		ebc3h	ebc3_addr.byte.high

#define		esur0_ebc3	ebc3_addr.bit.b0
#define		esur1_ebc3	ebc3_addr.bit.b1
#define		ewr0_ebc3	ebc3_addr.bit.b2
#define		ewr1_ebc3	ebc3_addr.bit.b3
#define		ehr_ebc3	ebc3_addr.bit.b4
#define		rdy_ebc3	ebc3_addr.bit.b5
#define		mpy0_ebc3	ebc3_addr.bit.b6
#define		mpy1_ebc3	ebc3_addr.bit.b7
#define		esuw0_ebc3	ebc3_addr.bit.b8
#define		esuw1_ebc3	ebc3_addr.bit.b9
#define		eww0_ebc3	ebc3_addr.bit.b10
#define		eww1_ebc3	ebc3_addr.bit.b11
#define		ehw_ebc3	ebc3_addr.bit.b12
#define		mpx_ebc3	ebc3_addr.bit.b13
#define		bw0_ebc3	ebc3_addr.bit.b14

/*------------------------------------------------------
	Chip Select 2-3 Boundary Setting Register
------------------------------------------------------*/
union byte_def cb23_addr;
#define     cb23	cb23_addr.byte

/*------------------------------------------------------
	Outer Bus Control Register 2
------------------------------------------------------*/
union word_def ebc2_addr;
#define		ebc2	ebc2_addr.word

#define		ebc2l	ebc2_addr.byte.low
#define		ebc2h	ebc2_addr.byte.high

#define		esur0_ebc2	ebc2_addr.bit.b0
#define		esur1_ebc2	ebc2_addr.bit.b1
#define		ewr0_ebc2	ebc2_addr.bit.b2
#define		ewr1_ebc2	ebc2_addr.bit.b3
#define		ehr_ebc2	ebc2_addr.bit.b4
#define		rdy_ebc2	ebc2_addr.bit.b5
#define		mpy0_ebc2	ebc2_addr.bit.b6
#define		mpy1_ebc2	ebc2_addr.bit.b7
#define		esuw0_ebc2	ebc2_addr.bit.b8
#define		esuw1_ebc2	ebc2_addr.bit.b9
#define		eww0_ebc2	ebc2_addr.bit.b10
#define		eww1_ebc2	ebc2_addr.bit.b11
#define		ehw_ebc2	ebc2_addr.bit.b12
#define		mpx_ebc2	ebc2_addr.bit.b13
#define		bw0_ebc2	ebc2_addr.bit.b14

/*------------------------------------------------------
	Chip Select 1-2 Boundary Setting Register
------------------------------------------------------*/
union byte_def cb12_addr;
#define     cb12	cb12_addr.byte

/*------------------------------------------------------
	Outer Bus Control Register 1
------------------------------------------------------*/
union word_def ebc1_addr;
#define		ebc1	ebc1_addr.word

#define		ebc1l	ebc1_addr.byte.low
#define		ebc1h	ebc1_addr.byte.high

#define		esur0_ebc1	ebc1_addr.bit.b0
#define		esur1_ebc1	ebc1_addr.bit.b1
#define		ewr0_ebc1	ebc1_addr.bit.b2
#define		ewr1_ebc1	ebc1_addr.bit.b3
#define		ehr_ebc1	ebc1_addr.bit.b4
#define		rdy_ebc1	ebc1_addr.bit.b5
#define		mpy0_ebc1	ebc1_addr.bit.b6
#define		mpy1_ebc1	ebc1_addr.bit.b7
#define		esuw0_ebc1	ebc1_addr.bit.b8
#define		esuw1_ebc1	ebc1_addr.bit.b9
#define		eww0_ebc1	ebc1_addr.bit.b10
#define		eww1_ebc1	ebc1_addr.bit.b11
#define		ehw_ebc1	ebc1_addr.bit.b12
#define		mpx_ebc1	ebc1_addr.bit.b13
#define		bw0_ebc1	ebc1_addr.bit.b14

/*------------------------------------------------------
	Chip Select 0-1 Boundary Setting Register
------------------------------------------------------*/
union byte_def cb01_addr;
#define     cb01	cb01_addr.byte

/*------------------------------------------------------
	Outer Bus Control Register 0
------------------------------------------------------*/
union word_def ebc0_addr;
#define		ebc0	ebc0_addr.word

#define		ebc0l	ebc0_addr.byte.low
#define		ebc0h	ebc0_addr.byte.high

#define		esur0_ebc0	ebc0_addr.bit.b0
#define		esur1_ebc0	ebc0_addr.bit.b1
#define		ewr0_ebc0	ebc0_addr.bit.b2
#define		ewr1_ebc0	ebc0_addr.bit.b3
#define		ehr_ebc0	ebc0_addr.bit.b4
#define		rdy_ebc0	ebc0_addr.bit.b5
#define		mpy0_ebc0	ebc0_addr.bit.b6
#define		mpy1_ebc0	ebc0_addr.bit.b7
#define		esuw0_ebc0	ebc0_addr.bit.b8
#define		esuw1_ebc0	ebc0_addr.bit.b9
#define		eww0_ebc0	ebc0_addr.bit.b10
#define		eww1_ebc0	ebc0_addr.bit.b11
#define		ehw_ebc0	ebc0_addr.bit.b12
#define		mpx_ebc0	ebc0_addr.bit.b13
#define		bw0_ebc0	ebc0_addr.bit.b14

/*------------------------------------------------------
	Flash Memory Rewrite Bus Control Register
------------------------------------------------------*/
union word_def febc_addr;
#define		febc	febc_addr.word

#define		febcl	febc_addr.byte.low
#define		febch	febc_addr.byte.high

#define		fwr0_febc	febc_addr.bit.b0
#define		fwr1_febc	febc_addr.bit.b1
#define		fwr2_febc	febc_addr.bit.b2
#define		fwr3_febc	febc_addr.bit.b3
#define		fwr4_febc	febc_addr.bit.b4
#define		mpy0_febc	febc_addr.bit.b6
#define		mpy1_febc	febc_addr.bit.b7
#define		fsuw0_febc	febc_addr.bit.b8
#define		fsuw1_febc	febc_addr.bit.b9
#define		fww0_febc	febc_addr.bit.b10
#define		fww1_febc	febc_addr.bit.b11

/*------------------------------------------------------
	Peripheal Bus Control Register
------------------------------------------------------*/
union word_def pbc_addr;
#define		pbc	pbc_addr.word

#define		pbcl	pbc_addr.byte.low
#define		pbch	pbc_addr.byte.high

#define		prd0		pbc_addr.bit.b0
#define		prd1		pbc_addr.bit.b1
#define		prd2		pbc_addr.bit.b2
#define		prd3		pbc_addr.bit.b3
#define		prd4		pbc_addr.bit.b4
#define		pwr0		pbc_addr.bit.b8
#define		pwr1		pbc_addr.bit.b9
#define		pwr2		pbc_addr.bit.b10
#define		pwr3		pbc_addr.bit.b11
#define		pwr4		pbc_addr.bit.b12
#define		exmpx		pbc_addr.bit.b13
#define		exbw0		pbc_addr.bit.b14

/*------------------------------------------------------
	timer b5 Interrupt Control Register
------------------------------------------------------*/
union byte_def tb5ic_addr;
#define		tb5ic	tb5ic_addr.byte

#define		ilvl0_tb5ic	tb5ic_addr.bit.b0
#define		ilvl1_tb5ic	tb5ic_addr.bit.b1
#define		ilvl2_tb5ic	tb5ic_addr.bit.b2
#define		ir_tb5ic	tb5ic_addr.bit.b3
/*------------------------------------------------------
	uart5 transmit/nack Interrupt Control Register
------------------------------------------------------*/
union byte_def s5tic_addr;
#define		s5tic	s5tic_addr.byte

#define		ilvl0_s5tic	s5tic_addr.bit.b0
#define		ilvl1_s5tic	s5tic_addr.bit.b1
#define		ilvl2_s5tic	s5tic_addr.bit.b2
#define		ir_s5tic	s5tic_addr.bit.b3

/*------------------------------------------------------
	Uart2 Receive/Ack Interrupt Contorol Register
------------------------------------------------------*/
union byte_def s2ric_addr;
#define		s2ric	s2ric_addr.byte

#define		ilvl0_s2ric s2ric_addr.bit.b0
#define		ilvl1_s2ric s2ric_addr.bit.b1
#define		ilvl2_s2ric s2ric_addr.bit.b2
#define		ir_s2ric	s2ric_addr.bit.b3

/*------------------------------------------------------
	uart6 transmit/nack Interrupt Control Register
------------------------------------------------------*/
union byte_def s6tic_addr;
#define		s6tic	s6tic_addr.byte

#define		ilvl0_s6tic s6tic_addr.bit.b0
#define		ilvl1_s6tic s6tic_addr.bit.b1
#define		ilvl2_s6tic s6tic_addr.bit.b2
#define		ir_s6tic	s6tic_addr.bit.b3

/*------------------------------------------------------
	uart3 receive/ack iterrupt Control Register
------------------------------------------------------*/
union byte_def s3ric_addr;
#define		s3ric	s3ric_addr.byte

#define		ilvl0_s3ric s3ric_addr.bit.b0
#define		ilvl1_s3ric s3ric_addr.bit.b1
#define		ilvl2_s3ric s3ric_addr.bit.b2
#define		ir_s3ric	s3ric_addr.bit.b3

/*------------------------------------------------------
	bus collision (uart5) interrput Control Register
------------------------------------------------------*/
union byte_def bcn5ic_addr;
#define		bcn5ic	bcn5ic_addr.byte

#define		ilvl0_bcn5ic bcn5ic_addr.bit.b0
#define		ilvl1_bcn5ic bcn5ic_addr.bit.b1
#define		ilvl2_bcn5ic bcn5ic_addr.bit.b2
#define		ir_bcn5ic	bcn5ic_addr.bit.b3

/*------------------------------------------------------
	bus collision (uart6) interrput Control Register
------------------------------------------------------*/
union byte_def bcn6ic_addr;
#define		bcn6ic	bcn6ic_addr.byte

#define		ilvl0_bcn6ic bcn6ic_addr.bit.b0
#define		ilvl1_bcn6ic bcn6ic_addr.bit.b1
#define		ilvl2_bcn6ic bcn6ic_addr.bit.b2
#define		ir_bcn6ic	bcn6ic_addr.bit.b3

/*------------------------------------------------------
	uart4 receive/ack Interrupt Control Register
------------------------------------------------------*/
union byte_def s4ric_addr;
#define		s4ric	s4ric_addr.byte

#define		ilvl0_s4ric s4ric_addr.bit.b0
#define		ilvl1_s4ric s4ric_addr.bit.b1
#define		ilvl2_s4ric s4ric_addr.bit.b2
#define		ir_s4ric	s4ric_addr.bit.b3

/*------------------------------------------------------
	Dma0 Interrupt Control Register
------------------------------------------------------*/
union byte_def dm0ic_addr;
#define		dm0ic	dm0ic_addr.byte

#define		ilvl0_dm0ic dm0ic_addr.bit.b0
#define		ilvl1_dm0ic dm0ic_addr.bit.b1
#define		ilvl2_dm0ic dm0ic_addr.bit.b2
#define		ir_dm0ic	dm0ic_addr.bit.b3

/*------------------------------------------------------
	bus collision (uart0) interrput Control Register
------------------------------------------------------*/
union byte_def bcn0ic_addr;
#define		bcn0ic	bcn0ic_addr.byte

#define		ilvl0_bcn0ic bcn0ic_addr.bit.b0
#define		ilvl1_bcn0ic bcn0ic_addr.bit.b1
#define		ilvl2_bcn0ic bcn0ic_addr.bit.b2
#define		ir_bcn0ic	bcn0ic_addr.bit.b3

/*------------------------------------------------------
	bus collision (uart3) interrput Control Register
------------------------------------------------------*/
union byte_def bcn3ic_addr;
#define		bcn3ic	bcn3ic_addr.byte

#define		ilvl0_bcn3ic bcn3ic_addr.bit.b0
#define		ilvl1_bcn3ic bcn3ic_addr.bit.b1
#define		ilvl2_bcn3ic bcn3ic_addr.bit.b2
#define		ir_bcn3ic	bcn3ic_addr.bit.b3

/*------------------------------------------------------
	Dma2 Interrupt Control Register
------------------------------------------------------*/
union byte_def dm2ic_addr;
#define		dm2ic	dm2ic_addr.byte

#define		ilvl0_dm2ic dm2ic_addr.bit.b0
#define		ilvl1_dm2ic dm2ic_addr.bit.b1
#define		ilvl2_dm2ic dm2ic_addr.bit.b2
#define		ir_dm2ic	dm2ic_addr.bit.b3

/*------------------------------------------------------
	a-d0 Interrupt Control Register
------------------------------------------------------*/
union byte_def ad0ic_addr;
#define		ad0ic	ad0ic_addr.byte

#define		ilvl0_ad0ic ad0ic_addr.bit.b0
#define		ilvl1_ad0ic ad0ic_addr.bit.b1
#define		ilvl2_ad0ic ad0ic_addr.bit.b2
#define		ir_ad0ic	ad0ic_addr.bit.b3

/*------------------------------------------------------
	Timer a0 Interrupt Control Register
------------------------------------------------------*/
union byte_def ta0ic_addr;
#define		ta0ic	ta0ic_addr.byte

#define		ilvl0_ta0ic ta0ic_addr.bit.b0
#define		ilvl1_ta0ic ta0ic_addr.bit.b1
#define		ilvl2_ta0ic ta0ic_addr.bit.b2
#define		ir_ta0ic	ta0ic_addr.bit.b3

/*------------------------------------------------------
	iio0 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio0ic_addr;
#define		iio0ic	iio0ic_addr.byte

#define		ilvl0_iio0ic iio0ic_addr.bit.b0
#define		ilvl1_iio0ic iio0ic_addr.bit.b1
#define		ilvl2_iio0ic iio0ic_addr.bit.b2
#define		ir_iio0ic	iio0ic_addr.bit.b3

/*------------------------------------------------------
	timer a2 Interrupt Control Register
------------------------------------------------------*/
union byte_def ta2ic_addr;
#define		ta2ic	ta2ic_addr.byte

#define		ilvl0_ta2ic ta2ic_addr.bit.b0
#define		ilvl1_ta2ic ta2ic_addr.bit.b1
#define		ilvl2_ta2ic ta2ic_addr.bit.b2
#define		ir_ta2ic	ta2ic_addr.bit.b3

/*------------------------------------------------------
	iio2 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio2ic_addr;
#define		iio2ic	iio2ic_addr.byte

#define		ilvl0_iio2ic iio2ic_addr.bit.b0
#define		ilvl1_iio2ic iio2ic_addr.bit.b1
#define		ilvl2_iio2ic iio2ic_addr.bit.b2
#define		ir_iio2ic	iio2ic_addr.bit.b3

/*------------------------------------------------------
	timer a4 Interrupt Control Register
------------------------------------------------------*/
union byte_def ta4ic_addr;
#define		ta4ic	ta4ic_addr.byte

#define		ilvl0_ta4ic ta4ic_addr.bit.b0
#define		ilvl1_ta4ic ta4ic_addr.bit.b1
#define		ilvl2_ta4ic ta4ic_addr.bit.b2
#define		ir_ta4ic	ta4ic_addr.bit.b3

/*------------------------------------------------------
	iio4 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio4ic_addr;
#define		iio4ic	iio4ic_addr.byte

#define		ilvl0_iio4ic iio4ic_addr.bit.b0
#define		ilvl1_iio4ic iio4ic_addr.bit.b1
#define		ilvl2_iio4ic iio4ic_addr.bit.b2
#define		ir_iio4ic	iio4ic_addr.bit.b3

/*------------------------------------------------------
	uart0 receive Interrupt Control Register
------------------------------------------------------*/
union byte_def s0ric_addr;
#define		s0ric	s0ric_addr.byte

#define		ilvl0_s0ric	s0ric_addr.bit.b0
#define		ilvl1_s0ric	s0ric_addr.bit.b1
#define		ilvl2_s0ric	s0ric_addr.bit.b2
#define		ir_s0ric	s0ric_addr.bit.b3

/*------------------------------------------------------
	iio6 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio6ic_addr;
#define		iio6ic	iio6ic_addr.byte

#define		ilvl0_iio6ic	iio6ic_addr.bit.b0
#define		ilvl1_iio6ic	iio6ic_addr.bit.b1
#define		ilvl2_iio6ic	iio6ic_addr.bit.b2
#define		ir_iio6ic	iio6ic_addr.bit.b3

/*------------------------------------------------------
	uart1 receive Interrupt Control Register
------------------------------------------------------*/
union byte_def s1ric_addr;
#define		s1ric	s1ric_addr.byte

#define		ilvl0_s1ric	s1ric_addr.bit.b0
#define		ilvl1_s1ric	s1ric_addr.bit.b1
#define		ilvl2_s1ric	s1ric_addr.bit.b2
#define		ir_s1ric	s1ric_addr.bit.b3

/*------------------------------------------------------
	iio8 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio8ic_addr;
#define		iio8ic	iio8ic_addr.byte

#define		ilvl0_iio8ic	iio8ic_addr.bit.b0
#define		ilvl1_iio8ic	iio8ic_addr.bit.b1
#define		ilvl2_iio8ic	iio8ic_addr.bit.b2
#define		ir_iio8ic	iio8ic_addr.bit.b3

/*------------------------------------------------------
	timer b1 Interrupt Control Register
------------------------------------------------------*/
union byte_def tb1ic_addr;
#define		tb1ic	tb1ic_addr.byte

#define		ilvl0_tb1ic	tb1ic_addr.bit.b0
#define		ilvl1_tb1ic	tb1ic_addr.bit.b1
#define		ilvl2_tb1ic	tb1ic_addr.bit.b2
#define		ir_tb1ic	tb1ic_addr.bit.b3

/*------------------------------------------------------
	iio10 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio10ic_addr;
#define		iio10ic	iio10ic_addr.byte

#define		ilvl0_iio10ic	iio10ic_addr.bit.b0
#define		ilvl1_iio10ic	iio10ic_addr.bit.b1
#define		ilvl2_iio10ic	iio10ic_addr.bit.b2
#define		ir_iio10ic	iio10ic_addr.bit.b3

/*------------------------------------------------------
	timer b3 Interrupt Control Register
------------------------------------------------------*/
union byte_def tb3ic_addr;
#define		tb3ic	tb3ic_addr.byte

#define		ilvl0_tb3ic	tb3ic_addr.bit.b0
#define		ilvl1_tb3ic	tb3ic_addr.bit.b1
#define		ilvl2_tb3ic	tb3ic_addr.bit.b2
#define		ir_tb3ic	tb3ic_addr.bit.b3

/*------------------------------------------------------
	int5 Interrupt Control Register
------------------------------------------------------*/
union byte_def int5ic_addr;
#define		int5ic	int5ic_addr.byte

#define		ilvl0_int5ic	int5ic_addr.bit.b0
#define		ilvl1_int5ic	int5ic_addr.bit.b1
#define		ilvl2_int5ic	int5ic_addr.bit.b2
#define		ir_int5ic	int5ic_addr.bit.b3
#define		pol_int5ic	int5ic_addr.bit.b4
#define		lvs_int5ic	int5ic_addr.bit.b5

/*------------------------------------------------------
	int3 Interrupt Control Register
------------------------------------------------------*/
union byte_def int3ic_addr;
#define		int3ic	int3ic_addr.byte

#define		ilvl0_int3ic	int3ic_addr.bit.b0
#define		ilvl1_int3ic	int3ic_addr.bit.b1
#define		ilvl2_int3ic	int3ic_addr.bit.b2
#define		ir_int3ic	int3ic_addr.bit.b3
#define		pol_int3ic	int3ic_addr.bit.b4
#define		lvs_int3ic	int3ic_addr.bit.b5

/*------------------------------------------------------
	int1 Interrupt Control Register
------------------------------------------------------*/
union byte_def int1ic_addr;
#define		int1ic	int1ic_addr.byte

#define		ilvl0_int1ic	int1ic_addr.bit.b0
#define		ilvl1_int1ic	int1ic_addr.bit.b1
#define		ilvl2_int1ic	int1ic_addr.bit.b2
#define		ir_int1ic	int1ic_addr.bit.b3
#define		pol_int1ic	int1ic_addr.bit.b4
#define		lvs_int1ic	int1ic_addr.bit.b5

/*------------------------------------------------------
	uart2 transmit/nack Interrupt Control Register
------------------------------------------------------*/
union byte_def s2tic_addr;
#define		s2tic	s2tic_addr.byte

#define		ilvl0_s2tic	s2tic_addr.bit.b0
#define		ilvl1_s2tic	s2tic_addr.bit.b1
#define		ilvl2_s2tic	s2tic_addr.bit.b2
#define		ir_s2tic	s2tic_addr.bit.b3

/*------------------------------------------------------
	uart5 receive/ack Interrupt Control Register
------------------------------------------------------*/
union byte_def s5ric_addr;
#define		s5ric	s5ric_addr.byte

#define		ilvl0_s5ric	s5ric_addr.bit.b0
#define		ilvl1_s5ric	s5ric_addr.bit.b1
#define		ilvl2_s5ric	s5ric_addr.bit.b2
#define		ir_s5ric	s5ric_addr.bit.b3

/*------------------------------------------------------
	uart3 transmit/nack Interrupt Control Register
------------------------------------------------------*/
union byte_def s3tic_addr;
#define		s3tic	s3tic_addr.byte

#define		ilvl0_s3tic	s3tic_addr.bit.b0
#define		ilvl1_s3tic	s3tic_addr.bit.b1
#define		ilvl2_s3tic	s3tic_addr.bit.b2
#define		ir_s3tic	s3tic_addr.bit.b3

/*------------------------------------------------------
	uart6 receive/ack Interrupt Control Register
------------------------------------------------------*/
union byte_def s6ric_addr;
#define		s6ric	s6ric_addr.byte

#define		ilvl0_s6ric	s6ric_addr.bit.b0
#define		ilvl1_s6ric	s6ric_addr.bit.b1
#define		ilvl2_s6ric	s6ric_addr.bit.b2
#define		ir_s6ric	s6ric_addr.bit.b3

/*------------------------------------------------------
	uart4 transmit/nack Interrupt Control Register
------------------------------------------------------*/
union byte_def s4tic_addr;
#define		s4tic	s4tic_addr.byte

#define		ilvl0_s4tic	s4tic_addr.bit.b0
#define		ilvl1_s4tic	s4tic_addr.bit.b1
#define		ilvl2_s4tic	s4tic_addr.bit.b2
#define		ir_s4tic	s4tic_addr.bit.b3

/*------------------------------------------------------
	bus collision (uart2) interrput Control Register
------------------------------------------------------*/
union byte_def bcn2ic_addr;
#define		bcn2ic	bcn2ic_addr.byte

#define		ilvl0_bcn2ic	bcn2ic_addr.bit.b0
#define		ilvl1_bcn2ic	bcn2ic_addr.bit.b1
#define		ilvl2_bcn2ic	bcn2ic_addr.bit.b2
#define		ir_bcn2ic	bcn2ic_addr.bit.b3

/*------------------------------------------------------
	dma1 Interrupt Control Register
------------------------------------------------------*/
union byte_def dm1ic_addr;
#define		dm1ic	dm1ic_addr.byte

#define		ilvl0_dm1ic	dm1ic_addr.bit.b0
#define		ilvl1_dm1ic	dm1ic_addr.bit.b1
#define		ilvl2_dm1ic	dm1ic_addr.bit.b2
#define		ir_dm1ic	dm1ic_addr.bit.b3

/*------------------------------------------------------
	bus collision (uart1) interrput Control Register
------------------------------------------------------*/
union byte_def bcn1ic_addr;
#define		bcn1ic	bcn1ic_addr.byte

#define		ilvl0_bcn1ic	bcn1ic_addr.bit.b0
#define		ilvl1_bcn1ic	bcn1ic_addr.bit.b1
#define		ilvl2_bcn1ic	bcn1ic_addr.bit.b2
#define		ir_bcn1ic	bcn1ic_addr.bit.b3

/*------------------------------------------------------
	bus collision (uart4) interrput Control Register
------------------------------------------------------*/
union byte_def bcn4ic_addr;
#define		bcn4ic	bcn4ic_addr.byte

#define		ilvl0_bcn4ic	bcn4ic_addr.bit.b0
#define		ilvl1_bcn4ic	bcn4ic_addr.bit.b1
#define		ilvl2_bcn4ic	bcn4ic_addr.bit.b2
#define		ir_bcn4ic	bcn4ic_addr.bit.b3

/*------------------------------------------------------
	dma3 Interrupt Control Register
------------------------------------------------------*/
union byte_def dm3ic_addr;
#define		dm3ic	dm3ic_addr.byte

#define		ilvl0_dm3ic	dm3ic_addr.bit.b0
#define		ilvl1_dm3ic	dm3ic_addr.bit.b1
#define		ilvl2_dm3ic	dm3ic_addr.bit.b2
#define		ir_dm3ic	dm3ic_addr.bit.b3

/*------------------------------------------------------
	key input interrput Control Register
------------------------------------------------------*/
union byte_def kupic_addr;
#define		kupic	kupic_addr.byte

#define		ilvl0_kupic	kupic_addr.bit.b0
#define		ilvl1_kupic	kupic_addr.bit.b1
#define		ilvl2_kupic	kupic_addr.bit.b2
#define		ir_kupic	kupic_addr.bit.b3

/*------------------------------------------------------
	timer a1 Interrupt Control Register
------------------------------------------------------*/
union byte_def ta1ic_addr;
#define		ta1ic	ta1ic_addr.byte

#define		ilvl0_ta1ic	ta1ic_addr.bit.b0
#define		ilvl1_ta1ic	ta1ic_addr.bit.b1
#define		ilvl2_ta1ic	ta1ic_addr.bit.b2
#define		ir_ta1ic	ta1ic_addr.bit.b3

/*------------------------------------------------------
	iio1 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio1ic_addr;
#define		iio1ic	iio1ic_addr.byte

#define		ilvl0_iio1ic	iio1ic_addr.bit.b0
#define		ilvl1_iio1ic	iio1ic_addr.bit.b1
#define		ilvl2_iio1ic	iio1ic_addr.bit.b2
#define		ir_iio1ic	iio1ic_addr.bit.b3

/*------------------------------------------------------
	timer a3 Interrupt Control Register
------------------------------------------------------*/
union byte_def ta3ic_addr;
#define		ta3ic	ta3ic_addr.byte

#define		ilvl0_ta3ic	ta3ic_addr.bit.b0
#define		ilvl1_ta3ic	ta3ic_addr.bit.b1
#define		ilvl2_ta3ic	ta3ic_addr.bit.b2
#define		ir_ta3ic	ta3ic_addr.bit.b3

/*------------------------------------------------------
	iio3 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio3ic_addr;
#define		iio3ic	iio3ic_addr.byte

#define		ilvl0_iio3ic	iio3ic_addr.bit.b0
#define		ilvl1_iio3ic	iio3ic_addr.bit.b1
#define		ilvl2_iio3ic	iio3ic_addr.bit.b2
#define		ir_iio3ic	iio3ic_addr.bit.b3

/*------------------------------------------------------
	uart0 transmit interrput Control Register
------------------------------------------------------*/
union byte_def s0tic_addr;
#define		s0tic	s0tic_addr.byte

#define		ilvl0_s0tic	s0tic_addr.bit.b0
#define		ilvl1_s0tic	s0tic_addr.bit.b1
#define		ilvl2_s0tic	s0tic_addr.bit.b2
#define		ir_s0tic	s0tic_addr.bit.b3

/*------------------------------------------------------
	iio5 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio5ic_addr;
#define		iio5ic	iio5ic_addr.byte

#define		ilvl0_iio5ic	iio5ic_addr.bit.b0
#define		ilvl1_iio5ic	iio5ic_addr.bit.b1
#define		ilvl2_iio5ic	iio5ic_addr.bit.b2
#define		ir_iio5ic	iio5ic_addr.bit.b3

/*------------------------------------------------------
	uart1 transmit interrput Control Register
------------------------------------------------------*/
union byte_def s1tic_addr;
#define		s1tic	s1tic_addr.byte

#define		ilvl0_s1tic	s1tic_addr.bit.b0
#define		ilvl1_s1tic	s1tic_addr.bit.b1
#define		ilvl2_s1tic	s1tic_addr.bit.b2
#define		ir_s1tic	s1tic_addr.bit.b3

/*------------------------------------------------------
	iio7 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio7ic_addr;
#define		iio7ic	iio7ic_addr.byte

#define		ilvl0_iio7ic	iio7ic_addr.bit.b0
#define		ilvl1_iio7ic	iio7ic_addr.bit.b1
#define		ilvl2_iio7ic	iio7ic_addr.bit.b2
#define		ir_iio7ic	iio7ic_addr.bit.b3

/*------------------------------------------------------
	timer b0 interrput Control Register
------------------------------------------------------*/
union byte_def tb0ic_addr;
#define		tb0ic	tb0ic_addr.byte

#define		ilvl0_tb0ic	tb0ic_addr.bit.b0
#define		ilvl1_tb0ic	tb0ic_addr.bit.b1
#define		ilvl2_tb0ic	tb0ic_addr.bit.b2
#define		ir_tb0ic	tb0ic_addr.bit.b3

/*------------------------------------------------------
	iio9 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio9ic_addr;
#define		iio9ic	iio9ic_addr.byte

#define		ilvl0_iio9ic	iio9ic_addr.bit.b0
#define		ilvl1_iio9ic	iio9ic_addr.bit.b1
#define		ilvl2_iio9ic	iio9ic_addr.bit.b2
#define		ir_iio9ic	iio9ic_addr.bit.b3

/*------------------------------------------------------
	timer b2 interrput Control Register
------------------------------------------------------*/
union byte_def tb2ic_addr;
#define		tb2ic	tb2ic_addr.byte

#define		ilvl0_tb2ic	tb2ic_addr.bit.b0
#define		ilvl1_tb2ic	tb2ic_addr.bit.b1
#define		ilvl2_tb2ic	tb2ic_addr.bit.b2
#define		ir_tb2ic	tb2ic_addr.bit.b3

/*------------------------------------------------------
	iio11 Interrupt Control Register
------------------------------------------------------*/
union byte_def iio11ic_addr;
#define		iio11ic	iio11ic_addr.byte

#define		ilvl0_iio11ic	iio11ic_addr.bit.b0
#define		ilvl1_iio11ic	iio11ic_addr.bit.b1
#define		ilvl2_iio11ic	iio11ic_addr.bit.b2
#define		ir_iio11ic	iio11ic_addr.bit.b3

/*------------------------------------------------------
	timer b4 interrput Control Register
------------------------------------------------------*/
union byte_def tb4ic_addr;
#define		tb4ic	tb4ic_addr.byte

#define		ilvl0_tb4ic	tb4ic_addr.bit.b0
#define		ilvl1_tb4ic	tb4ic_addr.bit.b1
#define		ilvl2_tb4ic	tb4ic_addr.bit.b2
#define		ir_tb4ic	tb4ic_addr.bit.b3

/*------------------------------------------------------
	int4 interrput Control Register
------------------------------------------------------*/
union byte_def int4ic_addr;
#define		int4ic	int4ic_addr.byte

#define		ilvl0_int4ic	int4ic_addr.bit.b0
#define		ilvl1_int4ic	int4ic_addr.bit.b1
#define		ilvl2_int4ic	int4ic_addr.bit.b2
#define		ir_int4ic	int4ic_addr.bit.b3
#define		pol_int4ic	int4ic_addr.bit.b4
#define		lvs_int4ic	int4ic_addr.bit.b5

/*------------------------------------------------------
	int2 interrput Control Register
------------------------------------------------------*/
union byte_def int2ic_addr;
#define		int2ic	int2ic_addr.byte

#define		ilvl0_int2ic	int2ic_addr.bit.b0
#define		ilvl1_int2ic	int2ic_addr.bit.b1
#define		ilvl2_int2ic	int2ic_addr.bit.b2
#define		ir_int2ic	int2ic_addr.bit.b3
#define		pol_int2ic	int2ic_addr.bit.b4
#define		lvs_int2ic	int2ic_addr.bit.b5

/*------------------------------------------------------
	int0 interrput Control Register
------------------------------------------------------*/
union byte_def int0ic_addr;
#define		int0ic	int0ic_addr.byte

#define		ilvl0_int0ic	int0ic_addr.bit.b0
#define		ilvl1_int0ic	int0ic_addr.bit.b1
#define		ilvl2_int0ic	int0ic_addr.bit.b2
#define		ir_int0ic	int0ic_addr.bit.b3
#define		pol_int0ic	int0ic_addr.bit.b4
#define		lvs_int0ic	int0ic_addr.bit.b5

/*------------------------------------------------------
	Interruption requirement Register 0
------------------------------------------------------*/
union byte_def iio0ir_addr;
#define		iio0ir	iio0ir_addr.byte

#define		tm02r	iio0ir_addr.bit.b1
#define		po02r	iio0ir_addr.bit.b1
#define		tm13r	iio0ir_addr.bit.b2
#define		po13r	iio0ir_addr.bit.b2

/*------------------------------------------------------
	Interruption requirement Register 1
------------------------------------------------------*/
union byte_def iio1ir_addr;
#define		iio1ir	iio1ir_addr.byte

#define		tm00r	iio1ir_addr.bit.b1
#define		po00r	iio1ir_addr.bit.b1
#define		tm14r	iio1ir_addr.bit.b2
#define		po14r	iio1ir_addr.bit.b2

/*------------------------------------------------------
	Interruption requirement Register 2
------------------------------------------------------*/
union byte_def iio2ir_addr;
#define		iio2ir	iio2ir_addr.byte

#define		tm12r	iio2ir_addr.bit.b2
#define		po12r	iio2ir_addr.bit.b2

/*------------------------------------------------------
	Interruption requirement Register 3
------------------------------------------------------*/
union byte_def iio3ir_addr;
#define		iio3ir	iio3ir_addr.byte

#define		tm03r	iio3ir_addr.bit.b1
#define		po03r	iio3ir_addr.bit.b1
#define		tm10r	iio3ir_addr.bit.b2
#define		po10r	iio3ir_addr.bit.b2

/*------------------------------------------------------
	Interruption requirement Register 4
------------------------------------------------------*/
union byte_def iio4ir_addr;
#define		iio4ir	iio4ir_addr.byte

#define		tm04r	iio4ir_addr.bit.b1
#define		po04r	iio4ir_addr.bit.b1
#define		tm17r	iio4ir_addr.bit.b2
#define		po17r	iio4ir_addr.bit.b2
#define		bt1r	iio4ir_addr.bit.b4

/*------------------------------------------------------
	Interruption requirement Register 5
------------------------------------------------------*/
union byte_def iio5ir_addr;
#define		iio5ir	iio5ir_addr.byte

#define		tm05r	iio5ir_addr.bit.b1
#define		po05r	iio5ir_addr.bit.b1
#define		po21r	iio5ir_addr.bit.b2
#define		sio2rr	iio5ir_addr.bit.b4

/*------------------------------------------------------
	Interruption requirement Register 6
------------------------------------------------------*/
union byte_def iio6ir_addr;
#define		iio6ir	iio6ir_addr.byte

#define		tm06r	iio6ir_addr.bit.b1
#define		po06r	iio6ir_addr.bit.b1
#define		po20r	iio6ir_addr.bit.b2
#define		sio2tr	iio6ir_addr.bit.b4

/*------------------------------------------------------
	Interruption requirement Register 7
------------------------------------------------------*/
union byte_def iio7ir_addr;
#define		iio7ir	iio7ir_addr.byte

#define		tm07r	iio7ir_addr.bit.b1
#define		po07r	iio7ir_addr.bit.b1
#define		po22r	iio7ir_addr.bit.b2
#define		bt0r	iio7ir_addr.bit.b4
#define		ie0r	iio7ir_addr.bit.b7

/*------------------------------------------------------
	Interruption requirement Register 8
------------------------------------------------------*/
union byte_def iio8ir_addr;
#define		iio8ir	iio8ir_addr.byte

#define		tm11r	iio8ir_addr.bit.b1
#define		po11r	iio8ir_addr.bit.b1
#define		bt2r	iio8ir_addr.bit.b4
#define		ie2r	iio8ir_addr.bit.b6
#define		ie1r	iio8ir_addr.bit.b7

/*------------------------------------------------------
	Interruption requirement Register 9
------------------------------------------------------*/
union byte_def iio9ir_addr;
#define		iio9ir	iio9ir_addr.byte

#define		tm15r	iio9ir_addr.bit.b1
#define		po15r	iio9ir_addr.bit.b1

/*------------------------------------------------------
	Interruption requirement Register 10
------------------------------------------------------*/
union byte_def iio10ir_addr;
#define		iio10ir	iio10ir_addr.byte

#define		tm16r	iio10ir_addr.bit.b1
#define		po16r	iio10ir_addr.bit.b1

/*------------------------------------------------------
	Interruption requirement Register 11
------------------------------------------------------*/
union byte_def iio11ir_addr;
#define		iio11ir	iio11ir_addr.byte

#define		tm01r	iio11ir_addr.bit.b1
#define		po01r	iio11ir_addr.bit.b1

/*------------------------------------------------------
	Interruption permission Register 0
------------------------------------------------------*/
union byte_def	iio0ie_addr;
#define		iio0ie	iio0ie_addr.byte

#define		irlt_iio0ie	iio0ie_addr.bit.b0
#define		tm02e	iio0ie_addr.bit.b1
#define		po02e	iio0ie_addr.bit.b1
#define		tm13e	iio0ie_addr.bit.b2
#define		po13e	iio0ie_addr.bit.b2

/*------------------------------------------------------
	Interruption permission Register 1
------------------------------------------------------*/
union byte_def	iio1ie_addr;
#define		iio1ie	iio1ie_addr.byte

#define		irlt_iio1ie	iio1ie_addr.bit.b0
#define		tm00e	iio1ie_addr.bit.b1
#define		po00e	iio1ie_addr.bit.b1
#define		tm14e	iio1ie_addr.bit.b2
#define		po14e	iio1ie_addr.bit.b2

/*------------------------------------------------------
	Interruption permission Register 2
------------------------------------------------------*/
union byte_def	iio2ie_addr;
#define		iio2ie	iio2ie_addr.byte

#define		irlt_iio2ie	iio2ie_addr.bit.b0
#define		tm12e	iio2ie_addr.bit.b2
#define		po12e	iio2ie_addr.bit.b2

/*------------------------------------------------------
	Interruption permission Register 3
------------------------------------------------------*/
union byte_def	iio3ie_addr;
#define		iio3ie	iio3ie_addr.byte

#define		irlt_iio3ie	iio3ie_addr.bit.b0
#define		tm03e	iio3ie_addr.bit.b1
#define		po03e	iio3ie_addr.bit.b1
#define		tm10e	iio3ie_addr.bit.b2
#define		po10e	iio3ie_addr.bit.b2

/*------------------------------------------------------
	Interruption permission Register 4
------------------------------------------------------*/
union byte_def	iio4ie_addr;
#define		iio4ie	iio4ie_addr.byte

#define		irlt_iio4ie	iio4ie_addr.bit.b0
#define		tm04e	iio4ie_addr.bit.b1
#define		po04e	iio4ie_addr.bit.b1
#define		tm17e	iio4ie_addr.bit.b2
#define		po17e	iio4ie_addr.bit.b2
#define		bt1e	iio4ie_addr.bit.b4

/*------------------------------------------------------
	Interruption permission Register 5
------------------------------------------------------*/
union byte_def	iio5ie_addr;
#define		iio5ie	iio5ie_addr.byte

#define		irlt_iio5ie	iio5ie_addr.bit.b0
#define		tm05e	iio5ie_addr.bit.b1
#define		po05e	iio5ie_addr.bit.b1
#define		po21e	iio5ie_addr.bit.b2
#define		sio2re	iio5ie_addr.bit.b4

/*------------------------------------------------------
	Interruption permission Register 6
------------------------------------------------------*/
union byte_def	iio6ie_addr;
#define		iio6ie	iio6ie_addr.byte

#define		irlt_iio6ie	iio6ie_addr.bit.b0
#define		tm06e	iio6ie_addr.bit.b1
#define		po06e	iio6ie_addr.bit.b1
#define		po20e	iio6ie_addr.bit.b2
#define		sio2te	iio6ie_addr.bit.b4

/*------------------------------------------------------
	Interruption permission Register 7
------------------------------------------------------*/
union byte_def	iio7ie_addr;
#define		iio7ie	iio7ie_addr.byte

#define		irlt_iio7ie	iio7ie_addr.bit.b0
#define		tm07e	iio7ie_addr.bit.b1
#define		po07e	iio7ie_addr.bit.b1
#define		po22e	iio7ie_addr.bit.b2
#define		bt0e	iio7ie_addr.bit.b4
#define		ie0e	iio7ie_addr.bit.b7

/*------------------------------------------------------
	Interruption permission Register 8
------------------------------------------------------*/
union byte_def	iio8ie_addr;
#define		iio8ie	iio8ie_addr.byte

#define		irlt_iio8ie	iio8ie_addr.bit.b0
#define		tm11e	iio8ie_addr.bit.b1
#define		po11e	iio8ie_addr.bit.b1
#define		bt2e	iio8ie_addr.bit.b4
#define		ie2e	iio8ie_addr.bit.b6
#define		ie1e	iio8ie_addr.bit.b7

/*------------------------------------------------------
	Interruption permission Register 9
------------------------------------------------------*/
union byte_def	iio9ie_addr;
#define		iio9ie	iio9ie_addr.byte

#define		irlt_iio9ie	iio9ie_addr.bit.b0
#define		tm15e	iio9ie_addr.bit.b1
#define		po15e	iio9ie_addr.bit.b1

/*------------------------------------------------------
	Interruption permission Register 10
------------------------------------------------------*/
union byte_def	iio10ie_addr;
#define		iio10ie	iio10ie_addr.byte

#define		irlt_iio10ie	iio10ie_addr.bit.b0
#define		tm16e	iio10ie_addr.bit.b1
#define		po16e	iio10ie_addr.bit.b1

/*------------------------------------------------------
	Interruption permission Register 11
------------------------------------------------------*/
union byte_def	iio11ie_addr;
#define		iio11ie	iio11ie_addr.byte

#define		irlt_iio11ie	iio11ie_addr.bit.b0
#define		tm01e	iio11ie_addr.bit.b1
#define		po01e	iio11ie_addr.bit.b1

/*------------------------------------------------------
	uart7 transmit/nack Interrupt Control Register
------------------------------------------------------*/
union byte_def s7tic_addr;
#define		s7tic	s7tic_addr.byte

#define		ilvl0_s7tic	s7tic_addr.bit.b0
#define		ilvl1_s7tic	s7tic_addr.bit.b1
#define		ilvl2_s7tic	s7tic_addr.bit.b2
#define		ir_s7tic	s7tic_addr.bit.b3

/*------------------------------------------------------
	uart8 transmit/nack Interrupt Control Register
------------------------------------------------------*/
union byte_def s8tic_addr;
#define		s8tic	s8tic_addr.byte

#define		ilvl0_s8tic	s8tic_addr.bit.b0
#define		ilvl1_s8tic	s8tic_addr.bit.b1
#define		ilvl2_s8tic	s8tic_addr.bit.b2
#define		ir_s8tic	s8tic_addr.bit.b3

/*------------------------------------------------------
	uart7 receive/ack Interrupt Control Register
------------------------------------------------------*/
union byte_def s7ric_addr;
#define		s7ric	s7ric_addr.byte

#define		ilvl0_s7ric	s7ric_addr.bit.b0
#define		ilvl1_s7ric	s7ric_addr.bit.b1
#define		ilvl2_s7ric	s7ric_addr.bit.b2
#define		ir_s7ric	s7ric_addr.bit.b3

/*------------------------------------------------------
	uart8 receive/ack Interrupt Control Register
------------------------------------------------------*/
union byte_def s8ric_addr;
#define		s8ric	s8ric_addr.byte

#define		ilvl0_s8ric	s8ric_addr.bit.b0
#define		ilvl1_s8ric	s8ric_addr.bit.b1
#define		ilvl2_s8ric	s8ric_addr.bit.b2
#define		ir_s8ric	s8ric_addr.bit.b3

/*------------------------------------------------------
	group1 time measurement Register 0
------------------------------------------------------*/
union word_def	g1tm0_addr;
#define		g1tm0	g1tm0_addr.word

#define		g1tm0l	g1tm0_addr.byte.low
#define		g1tm0h	g1tm0_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Register 0
------------------------------------------------------*/
union word_def	g1po0_addr;
#define		g1po0	g1po0_addr.word

#define		g1po0l	g1po0_addr.byte.low
#define		g1po0h	g1po0_addr.byte.high

/*------------------------------------------------------
	group1 time measurement Register 1
------------------------------------------------------*/
union word_def	g1tm1_addr;
#define		g1tm1	g1tm1_addr.word

#define		g1tm1l	g1tm1_addr.byte.low
#define		g1tm1h	g1tm1_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Register 1
------------------------------------------------------*/
union word_def	g1po1_addr;
#define		g1po1	g1po1_addr.word

#define		g1po1l	g1po1_addr.byte.low
#define		g1po1h	g1po1_addr.byte.high

/*------------------------------------------------------
	group1 time measurement Register 2
------------------------------------------------------*/
union word_def	g1tm2_addr;
#define		g1tm2	g1tm2_addr.word

#define		g1tm2l	g1tm2_addr.byte.low
#define		g1tm2h	g1tm2_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Register 2
------------------------------------------------------*/
union word_def	g1po2_addr;
#define		g1po2	g1po2_addr.word

#define		g1po2l	g1po2_addr.byte.low
#define		g1po2h	g1po2_addr.byte.high

/*------------------------------------------------------
	group1 time measurement Register 3
------------------------------------------------------*/
union word_def	g1tm3_addr;
#define		g1tm3	g1tm3_addr.word

#define		g1tm3l	g1tm3_addr.byte.low
#define		g1tm3h	g1tm3_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Register 3
------------------------------------------------------*/
union word_def	g1po3_addr;
#define		g1po3	g1po3_addr.word

#define		g1po3l	g1po3_addr.byte.low
#define		g1po3h	g1po3_addr.byte.high

/*------------------------------------------------------
	group1 time measurement Register 4
------------------------------------------------------*/
union word_def	g1tm4_addr;
#define		g1tm4	g1tm4_addr.word

#define		g1tm4l	g1tm4_addr.byte.low
#define		g1tm4h	g1tm4_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Register 4
------------------------------------------------------*/
union word_def	g1po4_addr;
#define		g1po4	g1po4_addr.word

#define		g1po4l	g1po4_addr.byte.low
#define		g1po4h	g1po4_addr.byte.high

/*------------------------------------------------------
	group1 time measurement Register 5
------------------------------------------------------*/
union word_def	g1tm5_addr;
#define		g1tm5	g1tm5_addr.word

#define		g1tm5l	g1tm5_addr.byte.low
#define		g1tm5h	g1tm5_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Register 5
------------------------------------------------------*/
union word_def	g1po5_addr;
#define		g1po5	g1po5_addr.word

#define		g1po5l	g1po5_addr.byte.low
#define		g1po5h	g1po5_addr.byte.high

/*------------------------------------------------------
	group1 time measurement Register 6
------------------------------------------------------*/
union word_def	g1tm6_addr;
#define		g1tm6	g1tm6_addr.word

#define		g1tm6l	g1tm6_addr.byte.low
#define		g1tm6h	g1tm6_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Register 6
------------------------------------------------------*/
union word_def	g1po6_addr;
#define		g1po6	g1po6_addr.word

#define		g1po6l	g1po6_addr.byte.low
#define		g1po6h	g1po6_addr.byte.high

/*------------------------------------------------------
	group1 time measurement Register 7
------------------------------------------------------*/
union word_def	g1tm7_addr;
#define		g1tm7	g1tm7_addr.word

#define		g1tm7l	g1tm7_addr.byte.low
#define		g1tm7h	g1tm7_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Register 7
------------------------------------------------------*/
union word_def	g1po7_addr;
#define		g1po7	g1po7_addr.word

#define		g1po7l	g1po7_addr.byte.low
#define		g1po7h	g1po7_addr.byte.high

/*------------------------------------------------------
	group1 pulse output Control Register 0
------------------------------------------------------*/
union byte_def	g1pocr0_addr;
#define		g1pocr0	g1pocr0_addr.byte

#define		mod0_g1pocr0	g1pocr0_addr.bit.b0
#define		mod1_g1pocr0	g1pocr0_addr.bit.b1
#define		mod2_g1pocr0	g1pocr0_addr.bit.b2
#define		ivl_g1pocr0		g1pocr0_addr.bit.b4
#define		rld_g1pocr0		g1pocr0_addr.bit.b5
#define		btre_g1pocr0	g1pocr0_addr.bit.b6
#define		inv_g1pocr0		g1pocr0_addr.bit.b7

/*------------------------------------------------------
	group1 pulse output Control Register 1
------------------------------------------------------*/
union byte_def	g1pocr1_addr;
#define		g1pocr1	g1pocr1_addr.byte

#define		mod0_g1pocr1	g1pocr1_addr.bit.b0
#define		mod1_g1pocr1	g1pocr1_addr.bit.b1
#define		mod2_g1pocr1	g1pocr1_addr.bit.b2
#define		ivl_g1pocr1		g1pocr1_addr.bit.b4
#define		rld_g1pocr1		g1pocr1_addr.bit.b5
#define		inv_g1pocr1		g1pocr1_addr.bit.b7

/*------------------------------------------------------
	group1 pulse output Control Register 2
------------------------------------------------------*/
union byte_def	g1pocr2_addr;
#define		g1pocr2	g1pocr2_addr.byte

#define		mod0_g1pocr2	g1pocr2_addr.bit.b0
#define		mod1_g1pocr2	g1pocr2_addr.bit.b1
#define		mod2_g1pocr2	g1pocr2_addr.bit.b2
#define		ivl_g1pocr2		g1pocr2_addr.bit.b4
#define		rld_g1pocr2		g1pocr2_addr.bit.b5
#define		inv_g1pocr2		g1pocr2_addr.bit.b7

/*------------------------------------------------------
	group1 pulse output Control Register 3
------------------------------------------------------*/
union byte_def	g1pocr3_addr;
#define		g1pocr3	g1pocr3_addr.byte

#define		mod0_g1pocr3	g1pocr3_addr.bit.b0
#define		mod1_g1pocr3	g1pocr3_addr.bit.b1
#define		mod2_g1pocr3	g1pocr3_addr.bit.b2
#define		ivl_g1pocr3		g1pocr3_addr.bit.b4
#define		rld_g1pocr3		g1pocr3_addr.bit.b5
#define		inv_g1pocr3		g1pocr3_addr.bit.b7

/*------------------------------------------------------
	group1 pulse output Control Register 4
------------------------------------------------------*/
union byte_def	g1pocr4_addr;
#define		g1pocr4	g1pocr4_addr.byte

#define		mod0_g1pocr4	g1pocr4_addr.bit.b0
#define		mod1_g1pocr4	g1pocr4_addr.bit.b1
#define		mod2_g1pocr4	g1pocr4_addr.bit.b2
#define		ivl_g1pocr4		g1pocr4_addr.bit.b4
#define		rld_g1pocr4		g1pocr4_addr.bit.b5
#define		inv_g1pocr4		g1pocr4_addr.bit.b7

/*------------------------------------------------------
	group1 pulse output Control Register 5
------------------------------------------------------*/
union byte_def	g1pocr5_addr;
#define		g1pocr5	g1pocr5_addr.byte

#define		mod0_g1pocr5	g1pocr5_addr.bit.b0
#define		mod1_g1pocr5	g1pocr5_addr.bit.b1
#define		mod2_g1pocr5	g1pocr5_addr.bit.b2
#define		ivl_g1pocr5		g1pocr5_addr.bit.b4
#define		rld_g1pocr5		g1pocr5_addr.bit.b5
#define		inv_g1pocr5		g1pocr5_addr.bit.b7

/*------------------------------------------------------
	group1 pulse output Control Register 6
------------------------------------------------------*/
union byte_def	g1pocr6_addr;
#define		g1pocr6	g1pocr6_addr.byte

#define		mod0_g1pocr6	g1pocr6_addr.bit.b0
#define		mod1_g1pocr6	g1pocr6_addr.bit.b1
#define		mod2_g1pocr6	g1pocr6_addr.bit.b2
#define		ivl_g1pocr6		g1pocr6_addr.bit.b4
#define		rld_g1pocr6		g1pocr6_addr.bit.b5
#define		inv_g1pocr6		g1pocr6_addr.bit.b7

/*------------------------------------------------------
	group1 pulse output Control Register 7
------------------------------------------------------*/
union byte_def	g1pocr7_addr;
#define		g1pocr7	g1pocr7_addr.byte

#define		mod0_g1pocr7	g1pocr7_addr.bit.b0
#define		mod1_g1pocr7	g1pocr7_addr.bit.b1
#define		mod2_g1pocr7	g1pocr7_addr.bit.b2
#define		ivl_g1pocr7		g1pocr7_addr.bit.b4
#define		rld_g1pocr7		g1pocr7_addr.bit.b5
#define		inv_g1pocr7		g1pocr7_addr.bit.b7

/*------------------------------------------------------
	group1 time measurement Control Register 0
------------------------------------------------------*/
union byte_def	g1tmcr0_addr;
#define		g1tmcr0	g1tmcr0_addr.byte

#define		cts0_g1tmcr0	g1tmcr0_addr.bit.b0
#define		ctd1_g1tmcr0	g1tmcr0_addr.bit.b1
#define		df0_g1tmcr0		g1tmcr0_addr.bit.b2
#define		df1_g1tmcr0		g1tmcr0_addr.bit.b3

/*------------------------------------------------------
	group1 time measurement Control Register 1
------------------------------------------------------*/
union byte_def	g1tmcr1_addr;
#define		g1tmcr1	g1tmcr1_addr.byte

#define		cts0_g1tmcr1	g1tmcr1_addr.bit.b0
#define		ctd1_g1tmcr1	g1tmcr1_addr.bit.b1
#define		df0_g1tmcr1		g1tmcr1_addr.bit.b2
#define		df1_g1tmcr1		g1tmcr1_addr.bit.b3

/*------------------------------------------------------
	group1 time measurement Control Register 2
------------------------------------------------------*/
union byte_def	g1tmcr2_addr;
#define		g1tmcr2	g1tmcr2_addr.byte

#define		cts0_g1tmcr2	g1tmcr2_addr.bit.b0
#define		ctd1_g1tmcr2	g1tmcr2_addr.bit.b1
#define		df0_g1tmcr2		g1tmcr2_addr.bit.b2
#define		df1_g1tmcr2		g1tmcr2_addr.bit.b3

/*------------------------------------------------------
	group1 time measurement Control Register 3
------------------------------------------------------*/
union byte_def	g1tmcr3_addr;
#define		g1tmcr3	g1tmcr3_addr.byte

#define		cts0_g1tmcr3	g1tmcr3_addr.bit.b0
#define		ctd1_g1tmcr3	g1tmcr3_addr.bit.b1
#define		df0_g1tmcr3		g1tmcr3_addr.bit.b2
#define		df1_g1tmcr3		g1tmcr3_addr.bit.b3

/*------------------------------------------------------
	group1 time measurement Control Register 4
------------------------------------------------------*/
union byte_def	g1tmcr4_addr;
#define		g1tmcr4	g1tmcr4_addr.byte

#define		cts0_g1tmcr4	g1tmcr4_addr.bit.b0
#define		ctd1_g1tmcr4	g1tmcr4_addr.bit.b1
#define		df0_g1tmcr4		g1tmcr4_addr.bit.b2
#define		df1_g1tmcr4		g1tmcr4_addr.bit.b3

/*------------------------------------------------------
	group1 time measurement Control Register 5
------------------------------------------------------*/
union byte_def	g1tmcr5_addr;
#define		g1tmcr5	g1tmcr5_addr.byte

#define		cts0_g1tmcr5	g1tmcr5_addr.bit.b0
#define		ctd1_g1tmcr5	g1tmcr5_addr.bit.b1
#define		df0_g1tmcr5		g1tmcr5_addr.bit.b2
#define		df1_g1tmcr5		g1tmcr5_addr.bit.b3

/*------------------------------------------------------
	group1 time measurement Control Register 6
------------------------------------------------------*/
union byte_def	g1tmcr6_addr;
#define		g1tmcr6	g1tmcr6_addr.byte

#define		cts0_g1tmcr6	g1tmcr6_addr.bit.b0
#define		ctd1_g1tmcr6	g1tmcr6_addr.bit.b1
#define		df0_g1tmcr6		g1tmcr6_addr.bit.b2
#define		df1_g1tmcr6		g1tmcr6_addr.bit.b3
#define		gt_g1tmcr6		g1tmcr6_addr.bit.b4
#define		goc_g1tmcr6		g1tmcr6_addr.bit.b5
#define		gsc_g1tmcr6		g1tmcr6_addr.bit.b6
#define		pr_g1tmcr6		g1tmcr6_addr.bit.b7

/*------------------------------------------------------
	group1 time measurement Control Register 7
------------------------------------------------------*/
union byte_def	g1tmcr7_addr;
#define		g1tmcr7	g1tmcr7_addr.byte

#define		cts0_g1tmcr7	g1tmcr7_addr.bit.b0
#define		ctd1_g1tmcr7	g1tmcr7_addr.bit.b1
#define		df0_g1tmcr7		g1tmcr7_addr.bit.b2
#define		df1_g1tmcr7		g1tmcr7_addr.bit.b3
#define		gt_g1tmcr7		g1tmcr7_addr.bit.b4
#define		goc_g1tmcr7		g1tmcr7_addr.bit.b5
#define		gsc_g1tmcr7		g1tmcr7_addr.bit.b6
#define		pr_g1tmcr7		g1tmcr7_addr.bit.b7

/*------------------------------------------------------
	group1 base timer Register
------------------------------------------------------*/
union word_def	g1bt_addr;
#define		g1bt	g1bt_addr.word

#define		g1btl	g1bt_addr.byte.low
#define		g1bth	g1bt_addr.byte.high

/*------------------------------------------------------
	group1 base timer Control Register 0
------------------------------------------------------*/
union byte_def		g1bcr0_addr;
#define		g1bcr0	g1bcr0_addr.byte

#define		bck0_g1bcr0		g1bcr0_addr.bit.b0
#define		bck1_g1bcr0		g1bcr0_addr.bit.b1
#define		div0_g1bcr0		g1bcr0_addr.bit.b2
#define		div1_g1bcr0		g1bcr0_addr.bit.b3
#define		div2_g1bcr0		g1bcr0_addr.bit.b4
#define		div3_g1bcr0		g1bcr0_addr.bit.b5
#define		div4_g1bcr0		g1bcr0_addr.bit.b6
#define		it_g1bcr0		g1bcr0_addr.bit.b7

/*------------------------------------------------------
	group1 base timer Control Register 1
------------------------------------------------------*/
union byte_def		g1bcr1_addr;
#define		g1bcr1	g1bcr1_addr.byte

#define		rts0_g1bcr1		g1bcr1_addr.bit.b0
#define		rts1_g1bcr1		g1bcr1_addr.bit.b1
#define		rts2_g1bcr1		g1bcr1_addr.bit.b2
#define		bts_g1bcr1		g1bcr1_addr.bit.b4
#define		ud0_g1bcr1		g1bcr1_addr.bit.b5
#define		ud1_g1bcr1		g1bcr1_addr.bit.b6

/*------------------------------------------------------
	group1 priscale reload Register 6
------------------------------------------------------*/
union byte_def	g1tpr6_addr;
#define		g1tpr6	g1tpr6_addr.byte

/*------------------------------------------------------
	group1 priscale reload Register 7
------------------------------------------------------*/
union byte_def	g1tpr7_addr;
#define		g1tpr7	g1tpr7_addr.byte

/*------------------------------------------------------
	group1 function enable Register
------------------------------------------------------*/
union byte_def	g1fe_addr;
#define		g1fe	g1fe_addr.byte

#define		ife0_g1fe	g1fe_addr.bit.b0
#define		ife1_g1fe	g1fe_addr.bit.b1
#define		ife2_g1fe	g1fe_addr.bit.b2
#define		ife3_g1fe	g1fe_addr.bit.b3
#define		ife4_g1fe	g1fe_addr.bit.b4
#define		ife5_g1fe	g1fe_addr.bit.b5
#define		ife6_g1fe	g1fe_addr.bit.b6
#define		ife7_g1fe	g1fe_addr.bit.b7

/*------------------------------------------------------
	group1 function select Register
------------------------------------------------------*/
union byte_def	g1fs_addr;
#define		g1fs	g1fs_addr.byte

#define		fsc0_g1fs	g1fs_addr.bit.b0
#define		fsc1_g1fs	g1fs_addr.bit.b1
#define		fsc2_g1fs	g1fs_addr.bit.b2
#define		fsc3_g1fs	g1fs_addr.bit.b3
#define		fsc4_g1fs	g1fs_addr.bit.b4
#define		fsc5_g1fs	g1fs_addr.bit.b5
#define		fsc6_g1fs	g1fs_addr.bit.b6
#define		fsc7_g1fs	g1fs_addr.bit.b7

/*------------------------------------------------------
	group2 pulse output Register 0
------------------------------------------------------*/
union word_def	g2po0_addr;
#define		g2po0	g2po0_addr.word

#define		g2po0l	g2po0_addr.byte.low
#define		g2po0h	g2po0_addr.byte.high

/*------------------------------------------------------
	group2 pulse output Register 1
------------------------------------------------------*/
union word_def	g2po1_addr;
#define		g2po1	g2po1_addr.word

#define		g2po1l	g2po1_addr.byte.low
#define		g2po1h	g2po1_addr.byte.high

/*------------------------------------------------------
	group2 pulse output Register 2
------------------------------------------------------*/
union word_def	g2po2_addr;
#define		g2po2	g2po2_addr.word

#define		g2po2l	g2po2_addr.byte.low
#define		g2po2h	g2po2_addr.byte.high

/*------------------------------------------------------
	group2 pulse output Register 3
------------------------------------------------------*/
union word_def	g2po3_addr;
#define		g2po3	g2po3_addr.word

#define		g2po3l	g2po3_addr.byte.low
#define		g2po3h	g2po3_addr.byte.high

/*------------------------------------------------------
	group2 pulse output Register 4
------------------------------------------------------*/
union word_def	g2po4_addr;
#define		g2po4	g2po4_addr.word

#define		g2po4l	g2po4_addr.byte.low
#define		g2po4h	g2po4_addr.byte.high

/*------------------------------------------------------
	group2 pulse output Register 5
------------------------------------------------------*/
union word_def	g2po5_addr;
#define		g2po5	g2po5_addr.word

#define		g2po5l	g2po5_addr.byte.low
#define		g2po5h	g2po5_addr.byte.high

/*------------------------------------------------------
	group2 pulse output Register 6
------------------------------------------------------*/
union word_def	g2po6_addr;
#define		g2po6	g2po6_addr.word

#define		g2po6l	g2po6_addr.byte.low
#define		g2po6h	g2po6_addr.byte.high

/*------------------------------------------------------
	group2 pulse output Register 7
------------------------------------------------------*/
union word_def	g2po7_addr;
#define		g2po7	g2po7_addr.word

#define		g2po7l	g2po7_addr.byte.low
#define		g2po7h	g2po7_addr.byte.high

/*------------------------------------------------------
	group2 pulse output Control Register 0
------------------------------------------------------*/
union byte_def	g2pocr0_addr;
#define		g2pocr0	g2pocr0_addr.byte

#define		mod0_g2pocr0	g2pocr0_addr.bit.b0
#define		mod1_g2pocr0	g2pocr0_addr.bit.b1
#define		mod2_g2pocr0	g2pocr0_addr.bit.b2
#define		prt_g2pocr0		g2pocr0_addr.bit.b3
#define		ivl_g2pocr0		g2pocr0_addr.bit.b4
#define		rld_g2pocr0		g2pocr0_addr.bit.b5
#define		rtp_g2pocr0		g2pocr0_addr.bit.b6
#define		inv_g2pocr0		g2pocr0_addr.bit.b7

/*------------------------------------------------------
	group2 pulse output Control Register 1
------------------------------------------------------*/
union byte_def	g2pocr1_addr;
#define		g2pocr1	g2pocr1_addr.byte

#define		mod0_g2pocr1	g2pocr1_addr.bit.b0
#define		mod1_g2pocr1	g2pocr1_addr.bit.b1
#define		mod2_g2pocr1	g2pocr1_addr.bit.b2
#define		prt_g2pocr1		g2pocr1_addr.bit.b3
#define		ivl_g2pocr1		g2pocr1_addr.bit.b4
#define		rld_g2pocr1		g2pocr1_addr.bit.b5
#define		rtp_g2pocr1		g2pocr1_addr.bit.b6
#define		inv_g2pocr1		g2pocr1_addr.bit.b7

/*------------------------------------------------------
	group2 pulse output Control Register 2
------------------------------------------------------*/
union byte_def	g2pocr2_addr;
#define		g2pocr2	g2pocr2_addr.byte

#define		mod0_g2pocr2	g2pocr2_addr.bit.b0
#define		mod1_g2pocr2	g2pocr2_addr.bit.b1
#define		mod2_g2pocr2	g2pocr2_addr.bit.b2
#define		prt_g2pocr2		g2pocr2_addr.bit.b3
#define		ivl_g2pocr2		g2pocr2_addr.bit.b4
#define		rld_g2pocr2		g2pocr2_addr.bit.b5
#define		rtp_g2pocr2		g2pocr2_addr.bit.b6
#define		inv_g2pocr2		g2pocr2_addr.bit.b7

/*------------------------------------------------------
	group2 pulse output Control Register 3
------------------------------------------------------*/
union byte_def	g2pocr3_addr;
#define		g2pocr3	g2pocr3_addr.byte

#define		mod0_g2pocr3	g2pocr3_addr.bit.b0
#define		mod1_g2pocr3	g2pocr3_addr.bit.b1
#define		mod2_g2pocr3	g2pocr3_addr.bit.b2
#define		prt_g2pocr3		g2pocr3_addr.bit.b3
#define		ivl_g2pocr3		g2pocr3_addr.bit.b4
#define		rld_g2pocr3		g2pocr3_addr.bit.b5
#define		rtp_g2pocr3		g2pocr3_addr.bit.b6
#define		inv_g2pocr3		g2pocr3_addr.bit.b7

/*------------------------------------------------------
	group2 pulse output Control Register 4
------------------------------------------------------*/
union byte_def	g2pocr4_addr;
#define		g2pocr4	g2pocr4_addr.byte

#define		mod0_g2pocr4	g2pocr4_addr.bit.b0
#define		mod1_g2pocr4	g2pocr4_addr.bit.b1
#define		mod2_g2pocr4	g2pocr4_addr.bit.b2
#define		prt_g2pocr4		g2pocr4_addr.bit.b3
#define		ivl_g2pocr4		g2pocr4_addr.bit.b4
#define		rld_g2pocr4		g2pocr4_addr.bit.b5
#define		rtp_g2pocr4		g2pocr4_addr.bit.b6
#define		inv_g2pocr4		g2pocr4_addr.bit.b7

/*------------------------------------------------------
	group2 pulse output Control Register 5
------------------------------------------------------*/
union byte_def	g2pocr5_addr;
#define		g2pocr5	g2pocr5_addr.byte

#define		mod0_g2pocr5	g2pocr5_addr.bit.b0
#define		mod1_g2pocr5	g2pocr5_addr.bit.b1
#define		mod2_g2pocr5	g2pocr5_addr.bit.b2
#define		prt_g2pocr5		g2pocr5_addr.bit.b3
#define		ivl_g2pocr5		g2pocr5_addr.bit.b4
#define		rld_g2pocr5		g2pocr5_addr.bit.b5
#define		rtp_g2pocr5		g2pocr5_addr.bit.b6
#define		inv_g2pocr5		g2pocr5_addr.bit.b7

/*------------------------------------------------------
	group2 pulse output Control Register 6
------------------------------------------------------*/
union byte_def	g2pocr6_addr;
#define		g2pocr6	g2pocr6_addr.byte

#define		mod0_g2pocr6	g2pocr6_addr.bit.b0
#define		mod1_g2pocr6	g2pocr6_addr.bit.b1
#define		mod2_g2pocr6	g2pocr6_addr.bit.b2
#define		prt_g2pocr6		g2pocr6_addr.bit.b3
#define		ivl_g2pocr6		g2pocr6_addr.bit.b4
#define		rld_g2pocr6		g2pocr6_addr.bit.b5
#define		rtp_g2pocr6		g2pocr6_addr.bit.b6
#define		inv_g2pocr6		g2pocr6_addr.bit.b7

/*------------------------------------------------------
	group2 pulse output Control Register 7
------------------------------------------------------*/
union byte_def	g2pocr7_addr;
#define		g2pocr7	g2pocr7_addr.byte

#define		mod0_g2pocr7	g2pocr7_addr.bit.b0
#define		mod1_g2pocr7	g2pocr7_addr.bit.b1
#define		mod2_g2pocr7	g2pocr7_addr.bit.b2
#define		prt_g2pocr7		g2pocr7_addr.bit.b3
#define		ivl_g2pocr7		g2pocr7_addr.bit.b4
#define		rld_g2pocr7		g2pocr7_addr.bit.b5
#define		rtp_g2pocr7		g2pocr7_addr.bit.b6
#define		inv_g2pocr7		g2pocr7_addr.bit.b7

/*------------------------------------------------------
	group2 base timer Register
------------------------------------------------------*/
union word_def	g2bt_addr;
#define		g2bt	g2bt_addr.word

#define		g2btl	g2bt_addr.byte.low
#define		g2bth	g2bt_addr.byte.high

/*------------------------------------------------------
	group2 base timer Control Register 0
------------------------------------------------------*/
union byte_def	g2bcr0_addr;
#define		g2bcr0	g2bcr0_addr.byte

#define		bck0_g2bcr0		g2bcr0_addr.bit.b0
#define		bck1_g2bcr0		g2bcr0_addr.bit.b1
#define		div0_g2bcr0		g2bcr0_addr.bit.b2
#define		div1_g2bcr0		g2bcr0_addr.bit.b3
#define		div2_g2bcr0		g2bcr0_addr.bit.b4
#define		div3_g2bcr0		g2bcr0_addr.bit.b5
#define		div4_g2bcr0		g2bcr0_addr.bit.b6
#define		it_g2bcr0		g2bcr0_addr.bit.b7

/*------------------------------------------------------
	group2 base timer Control Register 1
------------------------------------------------------*/
union byte_def	g2bcr1_addr;
#define		g2bcr1	g2bcr1_addr.byte

#define		rts0_g2bcr1		g2bcr1_addr.bit.b0
#define		rts1_g2bcr1		g2bcr1_addr.bit.b1
#define		rts2_g2bcr1		g2bcr1_addr.bit.b2
#define		bts_g2bcr1		g2bcr1_addr.bit.b4
#define		prp_g2bcr1		g2bcr1_addr.bit.b7

/*------------------------------------------------------
	Base timer Start Register
------------------------------------------------------*/
union byte_def	btsr_addr;
#define		btsr	btsr_addr.byte

#define		bt0s	btsr_addr.bit.b0
#define		bt1s	btsr_addr.bit.b1
#define		bt2s	btsr_addr.bit.b2

/*------------------------------------------------------
	group2 function enable Register
------------------------------------------------------*/
union byte_def	g2fe_addr;
#define		g2fe	g2fe_addr.byte

#define		ife0_g2fe	g2fe_addr.bit.b0
#define		ife1_g2fe	g2fe_addr.bit.b1
#define		ife2_g2fe	g2fe_addr.bit.b2
#define		ife3_g2fe	g2fe_addr.bit.b3
#define		ife4_g2fe	g2fe_addr.bit.b4
#define		ife5_g2fe	g2fe_addr.bit.b5
#define		ife6_g2fe	g2fe_addr.bit.b6
#define		ife7_g2fe	g2fe_addr.bit.b7

/*------------------------------------------------------
	group2 RTP Output Buffer Register
------------------------------------------------------*/
union byte_def	g2rtp_addr;
#define		g2rtp	g2rtp_addr.byte

#define		rtp0_g2rtp	g2rtp_addr.bit.b0
#define		rtp1_g2rtp	g2rtp_addr.bit.b1
#define		rtp2_g2rtp	g2rtp_addr.bit.b2
#define		rtp3_g2rtp	g2rtp_addr.bit.b3
#define		rtp4_g2rtp	g2rtp_addr.bit.b4
#define		rtp5_g2rtp	g2rtp_addr.bit.b5
#define		rtp6_g2rtp	g2rtp_addr.bit.b6
#define		rtp7_g2rtp	g2rtp_addr.bit.b7

/*------------------------------------------------------
	group2 SI/O Transmit Receive Mode Register
------------------------------------------------------*/
union byte_def	g2mr_addr;
#define		g2mr	g2mr_addr.byte

#define		gmd0_g2mr	g2mr_addr.bit.b0
#define		gmd1_g2mr	g2mr_addr.bit.b1
#define		ckdir_g2mr	g2mr_addr.bit.b2
#define		uform_g2mr	g2mr_addr.bit.b6
#define		irs_g2mr	g2mr_addr.bit.b7

/*------------------------------------------------------
	group2 SI/O Transmit Receive Control Register
------------------------------------------------------*/
union byte_def	g2cr_addr;
#define		g2cr	g2cr_addr.byte

#define		te_g2cr		g2cr_addr.bit.b0
#define		txept_g2cr	g2cr_addr.bit.b1
#define		ti_g2cr		g2cr_addr.bit.b2
#define		re_g2cr		g2cr_addr.bit.b4
#define		ri_g2cr		g2cr_addr.bit.b5
#define		opol_g2cr	g2cr_addr.bit.b6
#define		ipol_g2cr	g2cr_addr.bit.b7

/*------------------------------------------------------
	group2 SI/O Transmit Buffer Register
------------------------------------------------------*/
union word_def	g2tb_addr;
#define		g2tb	g2tb_addr.word

#define		g2tbl	g2tb_addr.byte.low
#define		g2tbh	g2tb_addr.byte.high

#define		sz0_g2tb	g2tb_addr.bit.b8
#define		sz1_g2tb	g2tb_addr.bit.b9
#define		sz2_g2tb	g2tb_addr.bit.b10
#define		a_g2tb		g2tb_addr.bit.b13
#define		pc_g2tb		g2tb_addr.bit.b14
#define		p_g2tb		g2tb_addr.bit.b15

/*------------------------------------------------------
	group2 SI/O Receive Buffer Register
------------------------------------------------------*/
union word_def	g2rb_addr;
#define		g2rb	g2rb_addr.word

#define		g2rbl	g2rb_addr.byte.low
#define		g2rbh	g2rb_addr.byte.high

#define		oer_g2rb	g2rb_addr.bit.b12

/*------------------------------------------------------
	group2 IEBus Address Register
------------------------------------------------------*/
union word_def	iear_addr;
#define		iear	iear_addr.word

#define		iearl	iear_addr.byte.low
#define		iearh	iear_addr.byte.high

/*------------------------------------------------------
	group2 IEBus Control Register
------------------------------------------------------*/
union byte_def	iecr_addr;
#define		iecr	iecr_addr.byte

#define		ieb_iecr	iecr_addr.bit.b0
#define		txept_iecr	iecr_addr.bit.b1
#define		iebbs_iecr	iecr_addr.bit.b2
#define		df_iecr		iecr_addr.bit.b6
#define		iem_iecr	iecr_addr.bit.b7

/*------------------------------------------------------
	group2 IEBus Transmit Interrupt Requiremet Register
------------------------------------------------------*/
union byte_def	ietif_addr;
#define		ietif	ietif_addr.byte

#define		ietnf_ietif	ietif_addr.bit.b0
#define		ieack_ietif	ietif_addr.bit.b1
#define		ietmb_ietif	ietif_addr.bit.b2
#define		iett_ietif	ietif_addr.bit.b3
#define		ieabl_ietif	ietif_addr.bit.b4

/*------------------------------------------------------
	group2 IEBus Receive Interrupt Requiremet Register
------------------------------------------------------*/
union byte_def	ierif_addr;
#define		ierif	ierif_addr.byte

#define		iernf_ierif		ierif_addr.bit.b0
#define		iepar_ierif		ierif_addr.bit.b1
#define		iermb_ierif		ierif_addr.bit.b2
#define		iert_ierif		ierif_addr.bit.b3
#define		ieretc_ierif	ierif_addr.bit.b4

/*------------------------------------------------------
	group0 time measurement Register 0
------------------------------------------------------*/
union word_def	g0tm0_addr;
#define		g0tm0	g0tm0_addr.word

#define		g0tm0l	g0tm0_addr.byte.low
#define		g0tm0h	g0tm0_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Register 0
------------------------------------------------------*/
union word_def	g0po0_addr;
#define		g0po0	g0po0_addr.word

#define		g0po0l	g0po0_addr.byte.low
#define		g0po0h	g0po0_addr.byte.high

/*------------------------------------------------------
	group0 time measurement Register 1
------------------------------------------------------*/
union word_def	g0tm1_addr;
#define		g0tm1	g0tm1_addr.word

#define		g0tm1l	g0tm1_addr.byte.low
#define		g0tm1h	g0tm1_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Register 1
------------------------------------------------------*/
union word_def	g0po1_addr;
#define		g0po1	g0po1_addr.word

#define		g0po1l	g0po1_addr.byte.low
#define		g0po1h	g0po1_addr.byte.high

/*------------------------------------------------------
	group0 time measurement Register 2
------------------------------------------------------*/
union word_def	g0tm2_addr;
#define		g0tm2	g0tm2_addr.word

#define		g0tm2l	g0tm2_addr.byte.low
#define		g0tm2h	g0tm2_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Register 2
------------------------------------------------------*/
union word_def	g0po2_addr;
#define		g0po2	g0po2_addr.word

#define		g0po2l	g0po2_addr.byte.low
#define		g0po2h	g0po2_addr.byte.high

/*------------------------------------------------------
	group0 time measurement Register 3
------------------------------------------------------*/
union word_def	g0tm3_addr;
#define		g0tm3	g0tm3_addr.word

#define		g0tm3l	g0tm3_addr.byte.low
#define		g0tm3h	g0tm3_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Register 3
------------------------------------------------------*/
union word_def	g0po3_addr;
#define		g0po3	g0po3_addr.word

#define		g0po3l	g0po3_addr.byte.low
#define		g0po3h	g0po3_addr.byte.high

/*------------------------------------------------------
	group0 time measurement Register 4
------------------------------------------------------*/
union word_def	g0tm4_addr;
#define		g0tm4	g0tm4_addr.word

#define		g0tm4l	g0tm4_addr.byte.low
#define		g0tm4h	g0tm4_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Register 4
------------------------------------------------------*/
union word_def	g0po4_addr;
#define		g0po4	g0po4_addr.word

#define		g0po4l	g0po4_addr.byte.low
#define		g0po4h	g0po4_addr.byte.high

/*------------------------------------------------------
	group0 time measurement Register 5
------------------------------------------------------*/
union word_def	g0tm5_addr;
#define		g0tm5	g0tm5_addr.word

#define		g0tm5l	g0tm5_addr.byte.low
#define		g0tm5h	g0tm5_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Register 5
------------------------------------------------------*/
union word_def	g0po5_addr;
#define		g0po5	g0po5_addr.word

#define		g0po5l	g0po5_addr.byte.low
#define		g0po5h	g0po5_addr.byte.high

/*------------------------------------------------------
	group0 time measurement Register 6
------------------------------------------------------*/
union word_def	g0tm6_addr;
#define		g0tm6	g0tm6_addr.word

#define		g0tm6l	g0tm6_addr.byte.low
#define		g0tm6h	g0tm6_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Register 6
------------------------------------------------------*/
union word_def	g0po6_addr;
#define		g0po6	g0po6_addr.word

#define		g0po6l	g0po6_addr.byte.low
#define		g0po6h	g0po6_addr.byte.high

/*------------------------------------------------------
	group0 time measurement Register 7
------------------------------------------------------*/
union word_def	g0tm7_addr;
#define		g0tm7	g0tm7_addr.word

#define		g0tm7l	g0tm7_addr.byte.low
#define		g0tm7h	g0tm7_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Register 7
------------------------------------------------------*/
union word_def	g0po7_addr;
#define		g0po7	g0po7_addr.word

#define		g0po7l	g0po7_addr.byte.low
#define		g0po7h	g0po7_addr.byte.high

/*------------------------------------------------------
	group0 pulse output Control Register 0
------------------------------------------------------*/
union byte_def	g0pocr0_addr;
#define		g0pocr0	g0pocr0_addr.byte

#define		mod0_g0pocr0	g0pocr0_addr.bit.b0
#define		mod1_g0pocr0	g0pocr0_addr.bit.b1
#define		mod2_g0pocr0	g0pocr0_addr.bit.b2
#define		ivl_g0pocr0		g0pocr0_addr.bit.b4
#define		rld_g0pocr0		g0pocr0_addr.bit.b5
#define		btre_g0pocr0	g0pocr0_addr.bit.b6
#define		inv_g0pocr0		g0pocr0_addr.bit.b7

/*------------------------------------------------------
	group0 pulse output Control Register 1
------------------------------------------------------*/
union byte_def	g0pocr1_addr;
#define		g0pocr1	g0pocr1_addr.byte

#define		mod0_g0pocr1	g0pocr1_addr.bit.b0
#define		mod1_g0pocr1	g0pocr1_addr.bit.b1
#define		mod2_g0pocr1	g0pocr1_addr.bit.b2
#define		ivl_g0pocr1		g0pocr1_addr.bit.b4
#define		rld_g0pocr1		g0pocr1_addr.bit.b5
#define		inv_g0pocr1		g0pocr1_addr.bit.b7

/*------------------------------------------------------
	group0 pulse output Control Register 2
------------------------------------------------------*/
union byte_def	g0pocr2_addr;
#define		g0pocr2	g0pocr2_addr.byte

#define		mod0_g0pocr2	g0pocr2_addr.bit.b0
#define		mod1_g0pocr2	g0pocr2_addr.bit.b1
#define		mod2_g0pocr2	g0pocr2_addr.bit.b2
#define		ivl_g0pocr2		g0pocr2_addr.bit.b4
#define		rld_g0pocr2		g0pocr2_addr.bit.b5
#define		inv_g0pocr2		g0pocr2_addr.bit.b7

/*------------------------------------------------------
	group0 pulse output Control Register 3
------------------------------------------------------*/
union byte_def	g0pocr3_addr;
#define		g0pocr3	g0pocr3_addr.byte

#define		mod0_g0pocr3	g0pocr3_addr.bit.b0
#define		mod1_g0pocr3	g0pocr3_addr.bit.b1
#define		mod2_g0pocr3	g0pocr3_addr.bit.b2
#define		ivl_g0pocr3		g0pocr3_addr.bit.b4
#define		rld_g0pocr3		g0pocr3_addr.bit.b5
#define		inv_g0pocr3		g0pocr3_addr.bit.b7

/*------------------------------------------------------
	group0 pulse output Control Register 4
------------------------------------------------------*/
union byte_def	g0pocr4_addr;
#define		g0pocr4	g0pocr4_addr.byte

#define		mod0_g0pocr4	g0pocr4_addr.bit.b0
#define		mod1_g0pocr4	g0pocr4_addr.bit.b1
#define		mod2_g0pocr4	g0pocr4_addr.bit.b2
#define		ivl_g0pocr4		g0pocr4_addr.bit.b4
#define		rld_g0pocr4		g0pocr4_addr.bit.b5
#define		inv_g0pocr4		g0pocr4_addr.bit.b7

/*------------------------------------------------------
	group0 pulse output Control Register 5
------------------------------------------------------*/
union byte_def	g0pocr5_addr;
#define		g0pocr5	g0pocr5_addr.byte

#define		mod0_g0pocr5	g0pocr5_addr.bit.b0
#define		mod1_g0pocr5	g0pocr5_addr.bit.b1
#define		mod2_g0pocr5	g0pocr5_addr.bit.b2
#define		ivl_g0pocr5		g0pocr5_addr.bit.b4
#define		rld_g0pocr5		g0pocr5_addr.bit.b5
#define		inv_g0pocr5		g0pocr5_addr.bit.b7

/*------------------------------------------------------
	group0 pulse output Control Register 6
------------------------------------------------------*/
union byte_def	g0pocr6_addr;
#define		g0pocr6	g0pocr6_addr.byte

#define		mod0_g0pocr6	g0pocr6_addr.bit.b0
#define		mod1_g0pocr6	g0pocr6_addr.bit.b1
#define		mod2_g0pocr6	g0pocr6_addr.bit.b2
#define		ivl_g0pocr6		g0pocr6_addr.bit.b4
#define		rld_g0pocr6		g0pocr6_addr.bit.b5
#define		inv_g0pocr6		g0pocr6_addr.bit.b7

/*------------------------------------------------------
	group0 pulse output Control Register 7
------------------------------------------------------*/
union byte_def	g0pocr7_addr;
#define		g0pocr7	g0pocr7_addr.byte

#define		mod0_g0pocr7	g0pocr7_addr.bit.b0
#define		mod1_g0pocr7	g0pocr7_addr.bit.b1
#define		mod2_g0pocr7	g0pocr7_addr.bit.b2
#define		ivl_g0pocr7		g0pocr7_addr.bit.b4
#define		rld_g0pocr7		g0pocr7_addr.bit.b5
#define		inv_g0pocr7		g0pocr7_addr.bit.b7

/*------------------------------------------------------
	group0 time measurement Control Register 0
------------------------------------------------------*/
union byte_def	g0tmcr0_addr;
#define		g0tmcr0	g0tmcr0_addr.byte

#define		cts0_g0tmcr0	g0tmcr0_addr.bit.b0
#define		ctd1_g0tmcr0	g0tmcr0_addr.bit.b1
#define		df0_g0tmcr0		g0tmcr0_addr.bit.b2
#define		df1_g0tmcr0		g0tmcr0_addr.bit.b3

/*------------------------------------------------------
	group0 time measurement Control Register 1
------------------------------------------------------*/
union byte_def	g0tmcr1_addr;
#define		g0tmcr1	g0tmcr1_addr.byte

#define		cts0_g0tmcr1	g0tmcr1_addr.bit.b0
#define		ctd1_g0tmcr1	g0tmcr1_addr.bit.b1
#define		df0_g0tmcr1		g0tmcr1_addr.bit.b2
#define		df1_g0tmcr1		g0tmcr1_addr.bit.b3

/*------------------------------------------------------
	group0 time measurement Control Register 2
------------------------------------------------------*/
union byte_def	g0tmcr2_addr;
#define		g0tmcr2	g0tmcr2_addr.byte

#define		cts0_g0tmcr2	g0tmcr2_addr.bit.b0
#define		ctd1_g0tmcr2	g0tmcr2_addr.bit.b1
#define		df0_g0tmcr2		g0tmcr2_addr.bit.b2
#define		df1_g0tmcr2		g0tmcr2_addr.bit.b3

/*------------------------------------------------------
	group0 time measurement Control Register 3
------------------------------------------------------*/
union byte_def	g0tmcr3_addr;
#define		g0tmcr3	g0tmcr3_addr.byte

#define		cts0_g0tmcr3	g0tmcr3_addr.bit.b0
#define		ctd1_g0tmcr3	g0tmcr3_addr.bit.b1
#define		df0_g0tmcr3		g0tmcr3_addr.bit.b2
#define		df1_g0tmcr3		g0tmcr3_addr.bit.b3

/*------------------------------------------------------
	group0 time measurement Control Register 4
------------------------------------------------------*/
union byte_def	g0tmcr4_addr;
#define		g0tmcr4	g0tmcr4_addr.byte

#define		cts0_g0tmcr4	g0tmcr4_addr.bit.b0
#define		ctd1_g0tmcr4	g0tmcr4_addr.bit.b1
#define		df0_g0tmcr4		g0tmcr4_addr.bit.b2
#define		df1_g0tmcr4		g0tmcr4_addr.bit.b3

/*------------------------------------------------------
	group0 time measurement Control Register 5
------------------------------------------------------*/
union byte_def	g0tmcr5_addr;
#define		g0tmcr5	g0tmcr5_addr.byte

#define		cts0_g0tmcr5	g0tmcr5_addr.bit.b0
#define		ctd1_g0tmcr5	g0tmcr5_addr.bit.b1
#define		df0_g0tmcr5		g0tmcr5_addr.bit.b2
#define		df1_g0tmcr5		g0tmcr5_addr.bit.b3

/*------------------------------------------------------
	group0 time measurement Control Register 6
------------------------------------------------------*/
union byte_def	g0tmcr6_addr;
#define		g0tmcr6	g0tmcr6_addr.byte

#define		cts0_g0tmcr6	g0tmcr6_addr.bit.b0
#define		ctd1_g0tmcr6	g0tmcr6_addr.bit.b1
#define		df0_g0tmcr6		g0tmcr6_addr.bit.b2
#define		df1_g0tmcr6		g0tmcr6_addr.bit.b3
#define		gt_g0tmcr6		g0tmcr6_addr.bit.b4
#define		goc_g0tmcr6		g0tmcr6_addr.bit.b5
#define		gsc_g0tmcr6		g0tmcr6_addr.bit.b6
#define		pr_g0tmcr6		g0tmcr6_addr.bit.b7

/*------------------------------------------------------
	group0 time measurement Control Register 7
------------------------------------------------------*/
union byte_def	g0tmcr7_addr;
#define		g0tmcr7	g0tmcr7_addr.byte

#define		cts0_g0tmcr7	g0tmcr7_addr.bit.b0
#define		ctd1_g0tmcr7	g0tmcr7_addr.bit.b1
#define		df0_g0tmcr7		g0tmcr7_addr.bit.b2
#define		df1_g0tmcr7		g0tmcr7_addr.bit.b3
#define		gt_g0tmcr7		g0tmcr7_addr.bit.b4
#define		goc_g0tmcr7		g0tmcr7_addr.bit.b5
#define		gsc_g0tmcr7		g0tmcr7_addr.bit.b6
#define		pr_g0tmcr7		g0tmcr7_addr.bit.b7

/*------------------------------------------------------
	group0 base timer Register
------------------------------------------------------*/
union word_def	g0bt_addr;
#define		g0bt	g0bt_addr.word

#define		g0btl	g0bt_addr.byte.low
#define		g0bth	g0bt_addr.byte.high

/*------------------------------------------------------
	group0 base timer Control Register 0
------------------------------------------------------*/
union byte_def	g0bcr0_addr;
#define		g0bcr0	g0bcr0_addr.byte

#define		bck0_g0bcr0		g0bcr0_addr.bit.b0
#define		bck1_g0bcr0		g0bcr0_addr.bit.b1
#define		div0_g0bcr0		g0bcr0_addr.bit.b2
#define		div1_g0bcr0		g0bcr0_addr.bit.b3
#define		div2_g0bcr0		g0bcr0_addr.bit.b4
#define		div3_g0bcr0		g0bcr0_addr.bit.b5
#define		div4_g0bcr0		g0bcr0_addr.bit.b6
#define		it_g0bcr0		g0bcr0_addr.bit.b7

/*------------------------------------------------------
	group0 base timer Control Register 1
------------------------------------------------------*/
union byte_def	g0bcr1_addr;
#define		g0bcr1	g0bcr1_addr.byte

#define		rts0_g0bcr1		g0bcr1_addr.bit.b0
#define		rts1_g0bcr1		g0bcr1_addr.bit.b1
#define		rts2_g0bcr1		g0bcr1_addr.bit.b2
#define		bts_g0bcr1		g0bcr1_addr.bit.b4
#define		ud0_g0bcr1		g0bcr1_addr.bit.b5
#define		ud1_g0bcr1		g0bcr1_addr.bit.b6

/*------------------------------------------------------
	group0 priscale reload Register 6
------------------------------------------------------*/
union byte_def	g0tpr6_addr;
#define		g0tpr6	g0tpr6_addr.byte

/*------------------------------------------------------
	group0 priscale reload Register 7
------------------------------------------------------*/
union byte_def	g0tpr7_addr;
#define		g0tpr7	g0tpr7_addr.byte

/*------------------------------------------------------
	group0 function enable Register
------------------------------------------------------*/
union byte_def	g0fe_addr;
#define		g0fe	g0fe_addr.byte

#define		ife0_g0fe	g0fe_addr.bit.b0
#define		ife1_g0fe	g0fe_addr.bit.b1
#define		ife2_g0fe	g0fe_addr.bit.b2
#define		ife3_g0fe	g0fe_addr.bit.b3
#define		ife4_g0fe	g0fe_addr.bit.b4
#define		ife5_g0fe	g0fe_addr.bit.b5
#define		ife6_g0fe	g0fe_addr.bit.b6
#define		ife7_g0fe	g0fe_addr.bit.b7

/*------------------------------------------------------
	group0 function select Register
------------------------------------------------------*/
union byte_def	g0fs_addr;
#define		g0fs	g0fs_addr.byte

#define		fsc0_g0fs	g0fs_addr.bit.b0
#define		fsc1_g0fs	g0fs_addr.bit.b1
#define		fsc2_g0fs	g0fs_addr.bit.b2
#define		fsc3_g0fs	g0fs_addr.bit.b3
#define		fsc4_g0fs	g0fs_addr.bit.b4
#define		fsc5_g0fs	g0fs_addr.bit.b5
#define		fsc6_g0fs	g0fs_addr.bit.b6
#define		fsc7_g0fs	g0fs_addr.bit.b7

/*------------------------------------------------------
	uart5 special mode Register 4
------------------------------------------------------*/
union byte_def	u5smr4_addr;
#define		u5smr4	u5smr4_addr.byte

#define		stareq_u5smr4	u5smr4_addr.bit.b0
#define		rstareq_u5smr4	u5smr4_addr.bit.b1
#define		stpreq_u5smr4	u5smr4_addr.bit.b2
#define		stspsel_u5smr4	u5smr4_addr.bit.b3
#define		ackd_u5smr4		u5smr4_addr.bit.b4
#define		ackc_u5smr4		u5smr4_addr.bit.b5
#define		sclhi_u5smr4	u5smr4_addr.bit.b6
#define		swc9_u5smr4		u5smr4_addr.bit.b7

/*------------------------------------------------------
	uart5 special mode Register 3
------------------------------------------------------*/
union byte_def	u5smr3_addr;
#define		u5smr3	u5smr3_addr.byte

#define		sse_u5smr3	u5smr3_addr.bit.b0
#define		ckph_u5smr3	u5smr3_addr.bit.b1
#define		dinc_u5smr3	u5smr3_addr.bit.b2
#define		nodc_u5smr3	u5smr3_addr.bit.b3
#define		err_u5smr3	u5smr3_addr.bit.b4
#define		dl0_u5smr3	u5smr3_addr.bit.b5
#define		dl1_u5smr3	u5smr3_addr.bit.b6
#define		dl2_u5smr3	u5smr3_addr.bit.b7

/*------------------------------------------------------
	uart5 special mode Register 2
------------------------------------------------------*/
union byte_def	u5smr2_addr;
#define		u5smr2	u5smr2_addr.byte

#define		iicm2_u5smr2	u5smr2_addr.bit.b0
#define		csc_u5smr2		u5smr2_addr.bit.b1
#define		swc_u5smr2		u5smr2_addr.bit.b2
#define		als_u5smr2		u5smr2_addr.bit.b3
#define		stc_u5smr2		u5smr2_addr.bit.b4
#define		swc2_u5smr2		u5smr2_addr.bit.b5
#define		sdhi_u5smr2		u5smr2_addr.bit.b6

/*------------------------------------------------------
	uart5 special mode Register
------------------------------------------------------*/
union byte_def	u5smr_addr;
#define		u5smr	u5smr_addr.byte

#define		iicm_u5smr		u5smr_addr.bit.b0
#define		abc_u5smr		u5smr_addr.bit.b1
#define		bbs_u5smr		u5smr_addr.bit.b2
#define		abscs_u5smr		u5smr_addr.bit.b4
#define		acse_u5smr		u5smr_addr.bit.b5
#define		sss_u5smr		u5smr_addr.bit.b6

/*------------------------------------------------------
	uart5 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u5mr_addr;
#define		u5mr	u5mr_addr.byte

#define		smd0_u5mr	u5mr_addr.bit.b0
#define		smd1_u5mr	u5mr_addr.bit.b1
#define		smd2_u5mr	u5mr_addr.bit.b2
#define		ckdir_u5mr	u5mr_addr.bit.b3
#define		stps_u5mr	u5mr_addr.bit.b4
#define		pry_u5mr	u5mr_addr.bit.b5
#define		prye_u5mr	u5mr_addr.bit.b6
#define		iopol_u5mr	u5mr_addr.bit.b7

/*------------------------------------------------------
	uart5 bit rate generator
------------------------------------------------------*/
union byte_def	u5brg_addr;
#define		u5brg	u5brg_addr.byte

/*------------------------------------------------------
	uart5 transmit buffer Register
------------------------------------------------------*/
union word_def	u5tb_addr;
#define		u5tb	u5tb_addr.word

#define		u5tbl	u5tb_addr.byte.low
#define		u5tbh	u5tb_addr.byte.high

/*------------------------------------------------------
	uart5 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u5c0_addr;
#define		u5c0	u5c0_addr.byte

#define		clk0_u5c0	u5c0_addr.bit.b0
#define		clk1_u5c0	u5c0_addr.bit.b1
#define		txept_u5c0	u5c0_addr.bit.b3
#define		crd_u5c0	u5c0_addr.bit.b4
#define		nch_u5c0	u5c0_addr.bit.b5
#define		ckpol_u5c0	u5c0_addr.bit.b6
#define		uform_u5c0	u5c0_addr.bit.b7

/*------------------------------------------------------
	uart5 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u5c1_addr;
#define		u5c1	u5c1_addr.byte

#define		te_u5c1			u5c1_addr.bit.b0
#define		ti_u5c1			u5c1_addr.bit.b1
#define		re_u5c1			u5c1_addr.bit.b2
#define		ri_u5c1			u5c1_addr.bit.b3
#define		u5irs_u5c1		u5c1_addr.bit.b4
#define		u5rrm_u5c1		u5c1_addr.bit.b5
#define		u5lch_u5c1		u5c1_addr.bit.b6

/*------------------------------------------------------
	uart5 receive buffer Register
------------------------------------------------------*/
union word_def	u5rb_addr;
#define		u5rb	u5rb_addr.word

#define		u5rbl		u5rb_addr.byte.low
#define		u5rbh		u5rb_addr.byte.high

#define		abt_u5rb	u5rb_addr.bit.b11
#define		oer_u5rb	u5rb_addr.bit.b12
#define		fer_u5rb	u5rb_addr.bit.b13
#define		per_u5rb	u5rb_addr.bit.b14
#define		sum_u5rb	u5rb_addr.bit.b15

/*------------------------------------------------------
	uart6 special mode Register 4
------------------------------------------------------*/
union byte_def	u6smr4_addr;
#define		u6smr4	u6smr4_addr.byte

#define		stareq_u6smr4	u6smr4_addr.bit.b0
#define		rstareq_u6smr4	u6smr4_addr.bit.b1
#define		stpreq_u6smr4	u6smr4_addr.bit.b2
#define		stspsel_u6smr4	u6smr4_addr.bit.b3
#define		ackd_u6smr4		u6smr4_addr.bit.b4
#define		ackc_u6smr4		u6smr4_addr.bit.b5
#define		sclhi_u6smr4	u6smr4_addr.bit.b6
#define		swc9_u6smr4		u6smr4_addr.bit.b7

/*------------------------------------------------------
	uart6 special mode Register 3
------------------------------------------------------*/
union byte_def	u6smr3_addr;
#define		u6smr3	u6smr3_addr.byte

#define		sse_u6smr3	u6smr3_addr.bit.b0
#define		ckph_u6smr3	u6smr3_addr.bit.b1
#define		dinc_u6smr3	u6smr3_addr.bit.b2
#define		nodc_u6smr3	u6smr3_addr.bit.b3
#define		err_u6smr3	u6smr3_addr.bit.b4
#define		dl0_u6smr3	u6smr3_addr.bit.b5
#define		dl1_u6smr3	u6smr3_addr.bit.b6
#define		dl2_u6smr3	u6smr3_addr.bit.b7

/*------------------------------------------------------
	uart6 special mode Register 2
------------------------------------------------------*/
union byte_def	u6smr2_addr;
#define		u6smr2	u6smr2_addr.byte

#define		iicm2_u6smr2	u6smr2_addr.bit.b0
#define		csc_u6smr2		u6smr2_addr.bit.b1
#define		swc_u6smr2		u6smr2_addr.bit.b2
#define		als_u6smr2		u6smr2_addr.bit.b3
#define		stc_u6smr2		u6smr2_addr.bit.b4
#define		swc2_u6smr2		u6smr2_addr.bit.b5
#define		sdhi_u6smr2		u6smr2_addr.bit.b6

/*------------------------------------------------------
	uart6 special mode Register
------------------------------------------------------*/
union byte_def	u6smr_addr;
#define		u6smr	u6smr_addr.byte

#define		iicm_u6smr		u6smr_addr.bit.b0
#define		abc_u6smr		u6smr_addr.bit.b1
#define		bbs_u6smr		u6smr_addr.bit.b2
#define		abscs_u6smr		u6smr_addr.bit.b4
#define		acse_u6smr		u6smr_addr.bit.b5
#define		sss_u6smr		u6smr_addr.bit.b6

/*------------------------------------------------------
	uart6 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u6mr_addr;
#define		u6mr	u6mr_addr.byte

#define		smd0_u6mr	u6mr_addr.bit.b0
#define		smd1_u6mr	u6mr_addr.bit.b1
#define		smd2_u6mr	u6mr_addr.bit.b2
#define		ckdir_u6mr	u6mr_addr.bit.b3
#define		stps_u6mr	u6mr_addr.bit.b4
#define		pry_u6mr	u6mr_addr.bit.b5
#define		prye_u6mr	u6mr_addr.bit.b6
#define		iopol_u6mr	u6mr_addr.bit.b7

/*------------------------------------------------------
	uart6 bit rate generator
------------------------------------------------------*/
union byte_def	u6brg_addr;
#define		u6brg	u6brg_addr.byte

/*------------------------------------------------------
	uart6 transmit buffer Register
------------------------------------------------------*/
union word_def	u6tb_addr;
#define		u6tb	u6tb_addr.word

#define		u6tbl	u6tb_addr.byte.low
#define		u6tbh	u6tb_addr.byte.high

/*------------------------------------------------------
	uart6 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u6c0_addr;
#define		u6c0	u6c0_addr.byte

#define		clk0_u6c0	u6c0_addr.bit.b0
#define		clk1_u6c0	u6c0_addr.bit.b1
#define		txept_u6c0	u6c0_addr.bit.b3
#define		crd_u6c0	u6c0_addr.bit.b4
#define		nch_u6c0	u6c0_addr.bit.b5
#define		ckpol_u6c0	u6c0_addr.bit.b6
#define		uform_u6c0	u6c0_addr.bit.b7

/*------------------------------------------------------
	uart6 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u6c1_addr;
#define		u6c1	u6c1_addr.byte

#define		te_u6c1			u6c1_addr.bit.b0
#define		ti_u6c1			u6c1_addr.bit.b1
#define		re_u6c1			u6c1_addr.bit.b2
#define		ri_u6c1			u6c1_addr.bit.b3
#define		u6irs_u6c1		u6c1_addr.bit.b4
#define		u6rrm_u6c1		u6c1_addr.bit.b5
#define		u6lch_u6c1		u6c1_addr.bit.b6

/*------------------------------------------------------
	uart6 receive buffer Register
------------------------------------------------------*/
union word_def	u6rb_addr;
#define		u6rb	u6rb_addr.word

#define		u6rbl		u6rb_addr.byte.low
#define		u6rbh		u6rb_addr.byte.high

#define		abt_u6rb	u6rb_addr.bit.b11
#define		oer_u6rb	u6rb_addr.bit.b12
#define		fer_u6rb	u6rb_addr.bit.b13
#define		per_u6rb	u6rb_addr.bit.b14
#define		sum_u6rb	u6rb_addr.bit.b15

/*------------------------------------------------------
	uart7 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u7mr_addr;
#define		u7mr	u7mr_addr.byte

#define		smd0_u7mr	u7mr_addr.bit.b0
#define		smd1_u7mr	u7mr_addr.bit.b1
#define		smd2_u7mr	u7mr_addr.bit.b2
#define		ckdir_u7mr	u7mr_addr.bit.b3
#define		stps_u7mr	u7mr_addr.bit.b4
#define		pry_u7mr	u7mr_addr.bit.b5
#define		prye_u7mr	u7mr_addr.bit.b6

/*------------------------------------------------------
	uart7 bit rate generator
------------------------------------------------------*/
union byte_def	u7brg_addr;
#define		u7brg	u7brg_addr.byte

/*------------------------------------------------------
	uart7 transmit buffer Register
------------------------------------------------------*/
union word_def	u7tb_addr;
#define		u7tb	u7tb_addr.word

#define		u7tbl	u7tb_addr.byte.low
#define		u7tbh	u7tb_addr.byte.high

/*------------------------------------------------------
	uart7 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u7c0_addr;
#define		u7c0	u7c0_addr.byte

#define		clk0_u7c0	u7c0_addr.bit.b0
#define		clk1_u7c0	u7c0_addr.bit.b1
#define		txept_u7c0	u7c0_addr.bit.b3
#define		crd_u7c0	u7c0_addr.bit.b4
#define		ckpol_u7c0	u7c0_addr.bit.b6
#define		uform_u7c0	u7c0_addr.bit.b7

/*------------------------------------------------------
	uart7 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u7c1_addr;
#define		u7c1	u7c1_addr.byte

#define		te_u7c1			u7c1_addr.bit.b0
#define		ti_u7c1			u7c1_addr.bit.b1
#define		re_u7c1			u7c1_addr.bit.b2
#define		ri_u7c1			u7c1_addr.bit.b3

/*------------------------------------------------------
	uart7 receive buffer Register
------------------------------------------------------*/
union word_def	u7rb_addr;
#define		u7rb	u7rb_addr.word

#define		u7rbl		u7rb_addr.byte.low
#define		u7rbh		u7rb_addr.byte.high

#define		oer_u7rb	u7rb_addr.bit.b12
#define		fer_u7rb	u7rb_addr.bit.b13
#define		per_u7rb	u7rb_addr.bit.b14
#define		sum_u7rb	u7rb_addr.bit.b15

/*------------------------------------------------------
	uart8 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u8mr_addr;
#define		u8mr	u8mr_addr.byte

#define		smd0_u8mr	u8mr_addr.bit.b0
#define		smd1_u8mr	u8mr_addr.bit.b1
#define		smd2_u8mr	u8mr_addr.bit.b2
#define		ckdir_u8mr	u8mr_addr.bit.b3
#define		stps_u8mr	u8mr_addr.bit.b4
#define		pry_u8mr	u8mr_addr.bit.b5
#define		prye_u8mr	u8mr_addr.bit.b6

/*------------------------------------------------------
	uart8 bit rate generator
------------------------------------------------------*/
union byte_def	u8brg_addr;
#define		u8brg	u8brg_addr.byte

/*------------------------------------------------------
	uart8 transmit buffer Register
------------------------------------------------------*/
union word_def	u8tb_addr;
#define		u8tb	u8tb_addr.word

#define		u8tbl	u8tb_addr.byte.low
#define		u8tbh	u8tb_addr.byte.high

/*------------------------------------------------------
	uart8 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u8c0_addr;
#define		u8c0	u8c0_addr.byte

#define		clk0_u8c0	u8c0_addr.bit.b0
#define		clk1_u8c0	u8c0_addr.bit.b1
#define		txept_u8c0	u8c0_addr.bit.b3
#define		crd_u8c0	u8c0_addr.bit.b4
#define		ckpol_u8c0	u8c0_addr.bit.b6
#define		uform_u8c0	u8c0_addr.bit.b7

/*------------------------------------------------------
	uart8 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u8c1_addr;
#define		u8c1	u8c1_addr.byte

#define		te_u8c1			u8c1_addr.bit.b0
#define		ti_u8c1			u8c1_addr.bit.b1
#define		re_u8c1			u8c1_addr.bit.b2
#define		ri_u8c1			u8c1_addr.bit.b3

/*------------------------------------------------------
	uart8 receive buffer Register
------------------------------------------------------*/
union word_def	u8rb_addr;
#define		u8rb	u8rb_addr.word

#define		u8rbl		u8rb_addr.byte.low
#define		u8rbh		u8rb_addr.byte.high

#define		oer_u8rb	u8rb_addr.bit.b12
#define		fer_u8rb	u8rb_addr.bit.b13
#define		per_u8rb	u8rb_addr.bit.b14
#define		sum_u8rb	u8rb_addr.bit.b15

/*------------------------------------------------------
	uart7,8 transmit receive Control Register 2
------------------------------------------------------*/
union byte_def	u78con_addr;
#define		u78con	u78con_addr.byte

#define		u7irs	u78con_addr.bit.b0
#define		u8irs	u78con_addr.bit.b1
#define		u7rrm	u78con_addr.bit.b2
#define		u8rrm	u78con_addr.bit.b3

/*------------------------------------------------------
	x0 Register
------------------------------------------------------*/
union word_def	x0r_addr;
#define		x0r	x0r_addr.word

#define		x0rl	x0r_addr.byte.low
#define		x0rh	x0r_addr.byte.high

/*------------------------------------------------------
	y0 Register
------------------------------------------------------*/
union word_def	y0r_addr;
#define		y0r	y0r_addr.word

#define		y0rl	y0r_addr.byte.low
#define		y0rh	y0r_addr.byte.high

/*------------------------------------------------------
	x1 Register
------------------------------------------------------*/
union word_def	x1r_addr;
#define		x1r	x1r_addr.word

#define		x1rl	x1r_addr.byte.low
#define		x1rh	x1r_addr.byte.high

/*------------------------------------------------------
	y1 Register
------------------------------------------------------*/
union word_def	y1r_addr;
#define		y1r	y1r_addr.word

#define		y1rl	y1r_addr.byte.low
#define		y1rh	y1r_addr.byte.high

/*------------------------------------------------------
	x2 Register
------------------------------------------------------*/
union word_def	x2r_addr;
#define		x2r	x2r_addr.word

#define		x2rl	x2r_addr.byte.low
#define		x2rh	x2r_addr.byte.high

/*------------------------------------------------------
	y2 Register
------------------------------------------------------*/
union word_def	y2r_addr;
#define		y2r	y2r_addr.word

#define		y2rl	y2r_addr.byte.low
#define		y2rh	y2r_addr.byte.high

/*------------------------------------------------------
	x3 Register
------------------------------------------------------*/
union word_def	x3r_addr;
#define		x3r	x3r_addr.word

#define		x3rl	x3r_addr.byte.low
#define		x3rh	x3r_addr.byte.high

/*------------------------------------------------------
	y3 Register
------------------------------------------------------*/
union word_def	y3r_addr;
#define		y3r	y3r_addr.word

#define		y3rl	y3r_addr.byte.low
#define		y3rh	y3r_addr.byte.high

/*------------------------------------------------------
	x4 Register
------------------------------------------------------*/
union word_def	x4r_addr;
#define		x4r	x4r_addr.word

#define		x4rl	x4r_addr.byte.low
#define		x4rh	x4r_addr.byte.high

/*------------------------------------------------------
	y4 Register
------------------------------------------------------*/
union word_def	y4r_addr;
#define		y4r	y4r_addr.word

#define		y4rl	y4r_addr.byte.low
#define		y4rh	y4r_addr.byte.high

/*------------------------------------------------------
	x5 Register
------------------------------------------------------*/
union word_def	x5r_addr;
#define		x5r	x5r_addr.word

#define		x5rl	x5r_addr.byte.low
#define		x5rh	x5r_addr.byte.high

/*------------------------------------------------------
	y5 Register
------------------------------------------------------*/
union word_def	y5r_addr;
#define		y5r	y5r_addr.word

#define		y5rl	y5r_addr.byte.low
#define		y5rh	y5r_addr.byte.high

/*------------------------------------------------------
	x6 Register
------------------------------------------------------*/
union word_def	x6r_addr;
#define		x6r	x6r_addr.word

#define		x6rl	x6r_addr.byte.low
#define		x6rh	x6r_addr.byte.high

/*------------------------------------------------------
	y6 Register
------------------------------------------------------*/
union word_def	y6r_addr;
#define		y6r	y6r_addr.word

#define		y6rl	y6r_addr.byte.low
#define		y6rh	y6r_addr.byte.high

/*------------------------------------------------------
	x7 Register
------------------------------------------------------*/
union word_def	x7r_addr;
#define		x7r	x7r_addr.word

#define		x7rl	x7r_addr.byte.low
#define		x7rh	x7r_addr.byte.high

/*------------------------------------------------------
	y7 Register
------------------------------------------------------*/
union word_def	y7r_addr;
#define		y7r	y7r_addr.word

#define		y7rl	y7r_addr.byte.low
#define		y7rh	y7r_addr.byte.high

/*------------------------------------------------------
	x8 Register
------------------------------------------------------*/
union word_def	x8r_addr;
#define		x8r	x8r_addr.word

#define		x8rl	x8r_addr.byte.low
#define		x8rh	x8r_addr.byte.high

/*------------------------------------------------------
	y8 Register
------------------------------------------------------*/
union word_def	y8r_addr;
#define		y8r	y8r_addr.word

#define		y8rl	y8r_addr.byte.low
#define		y8rh	y8r_addr.byte.high

/*------------------------------------------------------
	x9 Register
------------------------------------------------------*/
union word_def	x9r_addr;
#define		x9r	x9r_addr.word

#define		x9rl	x9r_addr.byte.low
#define		x9rh	x9r_addr.byte.high

/*------------------------------------------------------
	y9 Register
------------------------------------------------------*/
union word_def	y9r_addr;
#define		y9r	y9r_addr.word

#define		y9rl	y9r_addr.byte.low
#define		y9rh	y9r_addr.byte.high

/*------------------------------------------------------
	x10 Register
------------------------------------------------------*/
union word_def	x10r_addr;
#define		x10r	x10r_addr.word

#define		x10rl	x10r_addr.byte.low
#define		x10rh	x10r_addr.byte.high

/*------------------------------------------------------
	y10 Register
------------------------------------------------------*/
union word_def	y10r_addr;
#define		y10r	y10r_addr.word

#define		y10rl	y10r_addr.byte.low
#define		y10rh	y10r_addr.byte.high

/*------------------------------------------------------
	x11 Register
------------------------------------------------------*/
union word_def	x11r_addr;
#define		x11r	x11r_addr.word

#define		x11rl	x11r_addr.byte.low
#define		x11rh	x11r_addr.byte.high

/*------------------------------------------------------
	y11 Register
------------------------------------------------------*/
union word_def	y11r_addr;
#define		y11r	y11r_addr.word

#define		y11rl	y11r_addr.byte.low
#define		y11rh	y11r_addr.byte.high

/*------------------------------------------------------
	x12 Register
------------------------------------------------------*/
union word_def	x12r_addr;
#define		x12r	x12r_addr.word

#define		x12rl	x12r_addr.byte.low
#define		x12rh	x12r_addr.byte.high

/*------------------------------------------------------
	y12 Register
------------------------------------------------------*/
union word_def	y12r_addr;
#define		y12r	y12r_addr.word

#define		y12rl	y12r_addr.byte.low
#define		y12rh	y12r_addr.byte.high

/*------------------------------------------------------
	x13 Register
------------------------------------------------------*/
union word_def	x13r_addr;
#define		x13r	x13r_addr.word

#define		x13rl	x13r_addr.byte.low
#define		x13rh	x13r_addr.byte.high

/*------------------------------------------------------
	y13 Register
------------------------------------------------------*/
union word_def	y13r_addr;
#define		y13r	y13r_addr.word

#define		y13rl	y13r_addr.byte.low
#define		y13rh	y13r_addr.byte.high

/*------------------------------------------------------
	x14 Register
------------------------------------------------------*/
union word_def	x14r_addr;
#define		x14r	x14r_addr.word

#define		x14rl	x14r_addr.byte.low
#define		x14rh	x14r_addr.byte.high

/*------------------------------------------------------
	y14 Register
------------------------------------------------------*/
union word_def	y14r_addr;
#define		y14r	y14r_addr.word

#define		y14rl	y14r_addr.byte.low
#define		y14rh	y14r_addr.byte.high

/*------------------------------------------------------
	x15 Register
------------------------------------------------------*/
union word_def	x15r_addr;
#define		x15r	x15r_addr.word

#define		x15rl	x15r_addr.byte.low
#define		x15rh	x15r_addr.byte.high

/*------------------------------------------------------
	y15 Register
------------------------------------------------------*/
union word_def	y15r_addr;
#define		y15r	y15r_addr.word

#define		y15rl	y15r_addr.byte.low
#define		y15rh	y15r_addr.byte.high

/*------------------------------------------------------
	x-y Control Register
------------------------------------------------------*/
union byte_def	xyc_addr;
#define		xyc	xyc_addr.byte

#define		xyc0	xyc_addr.bit.b0
#define		xyc1	xyc_addr.bit.b1

/*------------------------------------------------------
	uart1 special mode Register 4
------------------------------------------------------*/
union byte_def	u1smr4_addr;
#define		u1smr4	u1smr4_addr.byte

#define		stareq_u1smr4	u1smr4_addr.bit.b0
#define		rstareq_u1smr4	u1smr4_addr.bit.b1
#define		stpreq_u1smr4	u1smr4_addr.bit.b2
#define		stspsel_u1smr4	u1smr4_addr.bit.b3
#define		ackd_u1smr4		u1smr4_addr.bit.b4
#define		ackc_u1smr4		u1smr4_addr.bit.b5
#define		sclhi_u1smr4	u1smr4_addr.bit.b6
#define		swc9_u1smr4		u1smr4_addr.bit.b7

/*------------------------------------------------------
	uart1 special mode Register 3
------------------------------------------------------*/
union byte_def	u1smr3_addr;
#define		u1smr3	u1smr3_addr.byte

#define		sse_u1smr3	u1smr3_addr.bit.b0
#define		ckph_u1smr3	u1smr3_addr.bit.b1
#define		dinc_u1smr3	u1smr3_addr.bit.b2
#define		nodc_u1smr3	u1smr3_addr.bit.b3
#define		err_u1smr3	u1smr3_addr.bit.b4
#define		dl0_u1smr3	u1smr3_addr.bit.b5
#define		dl1_u1smr3	u1smr3_addr.bit.b6
#define		dl2_u1smr3	u1smr3_addr.bit.b7

/*------------------------------------------------------
	uart1 special mode Register 2
------------------------------------------------------*/
union byte_def	u1smr2_addr;
#define		u1smr2	u1smr2_addr.byte

#define		iicm2_u1smr2	u1smr2_addr.bit.b0
#define		csc_u1smr2		u1smr2_addr.bit.b1
#define		swc_u1smr2		u1smr2_addr.bit.b2
#define		als_u1smr2		u1smr2_addr.bit.b3
#define		stc_u1smr2		u1smr2_addr.bit.b4
#define		swc2_u1smr2		u1smr2_addr.bit.b5
#define		sdhi_u1smr2		u1smr2_addr.bit.b6

/*------------------------------------------------------
	uart1 special mode Register
------------------------------------------------------*/
union byte_def	u1smr_addr;
#define		u1smr	u1smr_addr.byte

#define		iicm_u1smr		u1smr_addr.bit.b0
#define		abc_u1smr		u1smr_addr.bit.b1
#define		bbs_u1smr		u1smr_addr.bit.b2
#define		abscs_u1smr		u1smr_addr.bit.b4
#define		acse_u1smr		u1smr_addr.bit.b5
#define		sss_u1smr		u1smr_addr.bit.b6

/*------------------------------------------------------
	uart1 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u1mr_addr;
#define		u1mr	u1mr_addr.byte

#define		smd0_u1mr	u1mr_addr.bit.b0
#define		smd1_u1mr	u1mr_addr.bit.b1
#define		smd2_u1mr	u1mr_addr.bit.b2
#define		ckdir_u1mr	u1mr_addr.bit.b3
#define		stps_u1mr	u1mr_addr.bit.b4
#define		pry_u1mr	u1mr_addr.bit.b5
#define		prye_u1mr	u1mr_addr.bit.b6
#define		iopol_u1mr	u1mr_addr.bit.b7

/*------------------------------------------------------
	uart1 bit rate generator
------------------------------------------------------*/
union byte_def	u1brg_addr;
#define		u1brg	u1brg_addr.byte

/*------------------------------------------------------
	uart1 transmit buffer Register
------------------------------------------------------*/
union word_def	u1tb_addr;
#define		u1tb	u1tb_addr.word

#define		u1tbl	u1tb_addr.byte.low
#define		u1tbh	u1tb_addr.byte.high

/*------------------------------------------------------
	uart1 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u1c0_addr;
#define		u1c0	u1c0_addr.byte

#define		clk0_u1c0	u1c0_addr.bit.b0
#define		clk1_u1c0	u1c0_addr.bit.b1
#define		txept_u1c0	u1c0_addr.bit.b3
#define		crd_u1c0	u1c0_addr.bit.b4
#define		nch_u1c0	u1c0_addr.bit.b5
#define		ckpol_u1c0	u1c0_addr.bit.b6
#define		uform_u1c0	u1c0_addr.bit.b7

/*------------------------------------------------------
	uart1 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u1c1_addr;
#define		u1c1	u1c1_addr.byte

#define		te_u1c1			u1c1_addr.bit.b0
#define		ti_u1c1			u1c1_addr.bit.b1
#define		re_u1c1			u1c1_addr.bit.b2
#define		ri_u1c1			u1c1_addr.bit.b3
#define		u1irs_u1c1		u1c1_addr.bit.b4
#define		u1rrm_u1c1		u1c1_addr.bit.b5
#define		u1lch_u1c1		u1c1_addr.bit.b6

/*------------------------------------------------------
	uart1 receive buffer Register
------------------------------------------------------*/
union word_def	u1rb_addr;
#define		u1rb	u1rb_addr.word

#define		u1rbl		u1rb_addr.byte.low
#define		u1rbh		u1rb_addr.byte.high

#define		abt_u1rb	u1rb_addr.bit.b11
#define		oer_u1rb	u1rb_addr.bit.b12
#define		fer_u1rb	u1rb_addr.bit.b13
#define		per_u1rb	u1rb_addr.bit.b14
#define		sum_u1rb	u1rb_addr.bit.b15

/*------------------------------------------------------
	uart4 special mode Register 4
------------------------------------------------------*/
union byte_def	u4smr4_addr;
#define		u4smr4	u4smr4_addr.byte

#define		stareq_u4smr4	u4smr4_addr.bit.b0
#define		rstareq_u4smr4	u4smr4_addr.bit.b1
#define		stpreq_u4smr4	u4smr4_addr.bit.b2
#define		stspsel_u4smr4	u4smr4_addr.bit.b3
#define		ackd_u4smr4		u4smr4_addr.bit.b4
#define		ackc_u4smr4		u4smr4_addr.bit.b5
#define		sclhi_u4smr4	u4smr4_addr.bit.b6
#define		swc9_u4smr4		u4smr4_addr.bit.b7

/*------------------------------------------------------
	uart4 special mode Register 3
------------------------------------------------------*/
union byte_def	u4smr3_addr;
#define		u4smr3	u4smr3_addr.byte

#define		sse_u4smr3	u4smr3_addr.bit.b0
#define		ckph_u4smr3	u4smr3_addr.bit.b1
#define		dinc_u4smr3	u4smr3_addr.bit.b2
#define		nodc_u4smr3	u4smr3_addr.bit.b3
#define		err_u4smr3	u4smr3_addr.bit.b4
#define		dl0_u4smr3	u4smr3_addr.bit.b5
#define		dl1_u4smr3	u4smr3_addr.bit.b6
#define		dl2_u4smr3	u4smr3_addr.bit.b7

/*------------------------------------------------------
	uart4 special mode Register 2
------------------------------------------------------*/
union byte_def	u4smr2_addr;
#define		u4smr2	u4smr2_addr.byte

#define		iicm2_u4smr2	u4smr2_addr.bit.b0
#define		csc_u4smr2		u4smr2_addr.bit.b1
#define		swc_u4smr2		u4smr2_addr.bit.b2
#define		als_u4smr2		u4smr2_addr.bit.b3
#define		stc_u4smr2		u4smr2_addr.bit.b4
#define		swc2_u4smr2		u4smr2_addr.bit.b5
#define		sdhi_u4smr2		u4smr2_addr.bit.b6

/*------------------------------------------------------
	uart4 special mode Register
------------------------------------------------------*/
union byte_def	u4smr_addr;
#define		u4smr	u4smr_addr.byte

#define		iicm_u4smr		u4smr_addr.bit.b0
#define		abc_u4smr		u4smr_addr.bit.b1
#define		bbs_u4smr		u4smr_addr.bit.b2
#define		abscs_u4smr		u4smr_addr.bit.b4
#define		acse_u4smr		u4smr_addr.bit.b5
#define		sss_u4smr		u4smr_addr.bit.b6

/*------------------------------------------------------
	uart4 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u4mr_addr;
#define		u4mr	u4mr_addr.byte

#define		smd0_u4mr	u4mr_addr.bit.b0
#define		smd1_u4mr	u4mr_addr.bit.b1
#define		smd2_u4mr	u4mr_addr.bit.b2
#define		ckdir_u4mr	u4mr_addr.bit.b3
#define		stps_u4mr	u4mr_addr.bit.b4
#define		pry_u4mr	u4mr_addr.bit.b5
#define		prye_u4mr	u4mr_addr.bit.b6
#define		iopol_u4mr	u4mr_addr.bit.b7

/*------------------------------------------------------
	uart4 bit rate generator
------------------------------------------------------*/
union byte_def	u4brg_addr;
#define		u4brg	u4brg_addr.byte

/*------------------------------------------------------
	uart4 transmit buffer Register
------------------------------------------------------*/
union word_def	u4tb_addr;
#define		u4tb	u4tb_addr.word

#define		u4tbl	u4tb_addr.byte.low
#define		u4tbh	u4tb_addr.byte.high

/*------------------------------------------------------
	uart4 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u4c0_addr;
#define		u4c0	u4c0_addr.byte

#define		clk0_u4c0	u4c0_addr.bit.b0
#define		clk1_u4c0	u4c0_addr.bit.b1
#define		txept_u4c0	u4c0_addr.bit.b3
#define		crd_u4c0	u4c0_addr.bit.b4
#define		nch_u4c0	u4c0_addr.bit.b5
#define		ckpol_u4c0	u4c0_addr.bit.b6
#define		uform_u4c0	u4c0_addr.bit.b7

/*------------------------------------------------------
	uart4 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u4c1_addr;
#define		u4c1	u4c1_addr.byte

#define		te_u4c1			u4c1_addr.bit.b0
#define		ti_u4c1			u4c1_addr.bit.b1
#define		re_u4c1			u4c1_addr.bit.b2
#define		ri_u4c1			u4c1_addr.bit.b3
#define		u4irs_u4c1		u4c1_addr.bit.b4
#define		u4rrm_u4c1		u4c1_addr.bit.b5
#define		u4lch_u4c1		u4c1_addr.bit.b6

/*------------------------------------------------------
	uart4 receive buffer Register
------------------------------------------------------*/
union word_def	u4rb_addr;
#define		u4rb	u4rb_addr.word

#define		u4rbl		u4rb_addr.byte.low
#define		u4rbh		u4rb_addr.byte.high

#define		abt_u4rb	u4rb_addr.bit.b11
#define		oer_u4rb	u4rb_addr.bit.b12
#define		fer_u4rb	u4rb_addr.bit.b13
#define		per_u4rb	u4rb_addr.bit.b14
#define		sum_u4rb	u4rb_addr.bit.b15

/*------------------------------------------------------
	timer b3,4,5 count start flag
------------------------------------------------------*/
union byte_def	tbsr_addr;
#define		tbsr	tbsr_addr.byte

#define		tb3s	tbsr_addr.bit.b5
#define		tb4s	tbsr_addr.bit.b6
#define		tb5s	tbsr_addr.bit.b7

/*------------------------------------------------------
	timer a1-1 Register
------------------------------------------------------*/
union word_def	ta11_addr;
#define		ta11	ta11_addr.word

#define		ta11l	ta11_addr.byte.low
#define		ta11h	ta11_addr.byte.high

/*------------------------------------------------------
	timer a2-1 Register
------------------------------------------------------*/
union word_def	ta21_addr;
#define		ta21	ta21_addr.word

#define		ta21l	ta21_addr.byte.low
#define		ta21h	ta21_addr.byte.high

/*------------------------------------------------------
	timer a4-1 Register
------------------------------------------------------*/
union word_def	ta41_addr;
#define		ta41	ta41_addr.word

#define		ta41l	ta41_addr.byte.low
#define		ta41h	ta41_addr.byte.high

/*------------------------------------------------------
	three phase pwm Control Register 0
------------------------------------------------------*/
union byte_def	invc0_addr;
#define		invc0	invc0_addr.byte

#define		inv00	invc0_addr.bit.b0
#define		inv01	invc0_addr.bit.b1
#define		inv02	invc0_addr.bit.b2
#define		inv03	invc0_addr.bit.b3
#define		inv04	invc0_addr.bit.b4
#define		inv05	invc0_addr.bit.b5
#define		inv06	invc0_addr.bit.b6
#define		inv07	invc0_addr.bit.b7

/*------------------------------------------------------
	three phase pwm Control Register 1
------------------------------------------------------*/
union byte_def	invc1_addr;
#define		invc1	invc1_addr.byte

#define		inv10	invc0_addr.bit.b0
#define		inv11	invc0_addr.bit.b1
#define		inv12	invc0_addr.bit.b2
#define		inv13	invc0_addr.bit.b3
#define		inv14	invc0_addr.bit.b4
#define		inv15	invc0_addr.bit.b5
#define		inv16	invc0_addr.bit.b6

/*------------------------------------------------------
	three phase output buffer Register 0
------------------------------------------------------*/
union byte_def	idb0_addr;
#define		idb0	idb0_addr.byte

#define		du0		idb0_addr.bit.b0
#define		dub0	idb0_addr.bit.b1
#define		dv0		idb0_addr.bit.b2
#define		dvb0	idb0_addr.bit.b3
#define		dw0		idb0_addr.bit.b4
#define		dwb0	idb0_addr.bit.b5

/*------------------------------------------------------
	three phase output buffer Register 1
------------------------------------------------------*/
union byte_def	idb1_addr;
#define		idb1	idb1_addr.byte

#define		du1		idb1_addr.bit.b0
#define		dub1	idb1_addr.bit.b1
#define		dv1		idb1_addr.bit.b2
#define		dvb1	idb1_addr.bit.b3
#define		dw1		idb1_addr.bit.b4
#define		dwb1	idb1_addr.bit.b5

/*------------------------------------------------------
	dead time timer
------------------------------------------------------*/
union byte_def	dtt_addr;
#define		dtt	dtt_addr.byte

/*------------------------------------------------------
	timer b2 Interrupt occurrence frequency set counter
------------------------------------------------------*/
union byte_def	ictb2_addr;
#define		ictb2	ictb2_addr.byte

/*------------------------------------------------------
	timer b3 Register
------------------------------------------------------*/
union word_def	tb3_addr;
#define		tb3	tb3_addr.word

#define		tb3l	tb3_addr.byte.low
#define		tb3h	tb3_addr.byte.high

/*------------------------------------------------------
	timer b4 Register
------------------------------------------------------*/
union word_def	tb4_addr;
#define		tb4	tb4_addr.word

#define		tb4l	tb4_addr.byte.low
#define		tb4h	tb4_addr.byte.high

/*------------------------------------------------------
	timer 55 Register
------------------------------------------------------*/
union word_def	tb5_addr;
#define		tb5	tb5_addr.word

#define		tb5l	tb5_addr.byte.low
#define		tb5h	tb5_addr.byte.high

/*------------------------------------------------------
	timer b3 mode Register
------------------------------------------------------*/
union byte_def	tb3mr_addr;
#define		tb3mr	tb3mr_addr.byte

#define		tmod0_tb3mr	tb3mr_addr.bit.b0
#define		tmod1_tb3mr	tb3mr_addr.bit.b1
#define		mr0_tb3mr	tb3mr_addr.bit.b2
#define		mr1_tb3mr	tb3mr_addr.bit.b3
#define		mr2_tb3mr	tb3mr_addr.bit.b4
#define		mr3_tb3mr	tb3mr_addr.bit.b5
#define		tck0_tb3mr	tb3mr_addr.bit.b6
#define		tck1_tb3mr	tb3mr_addr.bit.b7

/*------------------------------------------------------
	timer b4 mode Register
------------------------------------------------------*/
union byte_def	tb4mr_addr;
#define		tb4mr	tb4mr_addr.byte

#define		tmod0_tb4mr	tb4mr_addr.bit.b0
#define		tmod1_tb4mr	tb4mr_addr.bit.b1
#define		mr0_tb4mr	tb4mr_addr.bit.b2
#define		mr1_tb4mr	tb4mr_addr.bit.b3
#define		mr2_tb4mr	tb4mr_addr.bit.b4
#define		mr3_tb4mr	tb4mr_addr.bit.b5
#define		tck0_tb4mr	tb4mr_addr.bit.b6
#define		tck1_tb4mr	tb4mr_addr.bit.b7

/*------------------------------------------------------
	timer b5 mode Register
------------------------------------------------------*/
union byte_def	tb5mr_addr;
#define		tb5mr	tb5mr_addr.byte

#define		tmod0_tb5mr	tb5mr_addr.bit.b0
#define		tmod1_tb5mr	tb5mr_addr.bit.b1
#define		mr0_tb5mr	tb5mr_addr.bit.b2
#define		mr1_tb5mr	tb5mr_addr.bit.b3
#define		mr2_tb5mr	tb5mr_addr.bit.b4
#define		mr3_tb5mr	tb5mr_addr.bit.b5
#define		tck0_tb5mr	tb5mr_addr.bit.b6
#define		tck1_tb5mr	tb5mr_addr.bit.b7

/*------------------------------------------------------
	uart3 special mode Register 4
------------------------------------------------------*/
union byte_def	u3smr4_addr;
#define		u3smr4	u3smr4_addr.byte

#define		stareq_u3smr4	u3smr4_addr.bit.b0
#define		rstareq_u3smr4	u3smr4_addr.bit.b1
#define		stpreq_u3smr4	u3smr4_addr.bit.b2
#define		stspsel_u3smr4	u3smr4_addr.bit.b3
#define		ackd_u3smr4		u3smr4_addr.bit.b4
#define		ackc_u3smr4		u3smr4_addr.bit.b5
#define		sclhi_u3smr4	u3smr4_addr.bit.b6
#define		swc9_u3smr4		u3smr4_addr.bit.b7

/*------------------------------------------------------
	uart3 special mode Register 3
------------------------------------------------------*/
union byte_def	u3smr3_addr;
#define		u3smr3	u3smr3_addr.byte

#define		sse_u3smr3	u3smr3_addr.bit.b0
#define		ckph_u3smr3	u3smr3_addr.bit.b1
#define		dinc_u3smr3	u3smr3_addr.bit.b2
#define		nodc_u3smr3	u3smr3_addr.bit.b3
#define		err_u3smr3	u3smr3_addr.bit.b4
#define		dl0_u3smr3	u3smr3_addr.bit.b5
#define		dl1_u3smr3	u3smr3_addr.bit.b6
#define		dl2_u3smr3	u3smr3_addr.bit.b7

/*------------------------------------------------------
	uart3 special mode Register 2
------------------------------------------------------*/
union byte_def	u3smr2_addr;
#define		u3smr2	u3smr2_addr.byte

#define		iicm2_u3smr2	u3smr2_addr.bit.b0
#define		csc_u3smr2		u3smr2_addr.bit.b1
#define		swc_u3smr2		u3smr2_addr.bit.b2
#define		als_u3smr2		u3smr2_addr.bit.b3
#define		stc_u3smr2		u3smr2_addr.bit.b4
#define		swc2_u3smr2		u3smr2_addr.bit.b5
#define		sdhi_u3smr2		u3smr2_addr.bit.b6

/*------------------------------------------------------
	uart3 special mode Register
------------------------------------------------------*/
union byte_def	u3smr_addr;
#define		u3smr	u3smr_addr.byte

#define		iicm_u3smr		u3smr_addr.bit.b0
#define		abc_u3smr		u3smr_addr.bit.b1
#define		bbs_u3smr		u3smr_addr.bit.b2
#define		abscs_u3smr		u3smr_addr.bit.b4
#define		acse_u3smr		u3smr_addr.bit.b5
#define		sss_u3smr		u3smr_addr.bit.b6

/*------------------------------------------------------
	uart3 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u3mr_addr;
#define		u3mr	u3mr_addr.byte

#define		smd0_u3mr	u3mr_addr.bit.b0
#define		smd1_u3mr	u3mr_addr.bit.b1
#define		smd2_u3mr	u3mr_addr.bit.b2
#define		ckdir_u3mr	u3mr_addr.bit.b3
#define		stps_u3mr	u3mr_addr.bit.b4
#define		pry_u3mr	u3mr_addr.bit.b5
#define		prye_u3mr	u3mr_addr.bit.b6
#define		iopol_u3mr	u3mr_addr.bit.b7

/*------------------------------------------------------
	uart3 bit rate generator
------------------------------------------------------*/
union byte_def	u3brg_addr;
#define		u3brg	u3brg_addr.byte

/*------------------------------------------------------
	uart3 transmit buffer Register
------------------------------------------------------*/
union word_def	u3tb_addr;
#define		u3tb	u3tb_addr.word

#define		u3tbl	u3tb_addr.byte.low
#define		u3tbh	u3tb_addr.byte.high

/*------------------------------------------------------
	uart3 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u3c0_addr;
#define		u3c0	u3c0_addr.byte

#define		clk0_u3c0	u3c0_addr.bit.b0
#define		clk1_u3c0	u3c0_addr.bit.b1
#define		txept_u3c0	u3c0_addr.bit.b3
#define		crd_u3c0	u3c0_addr.bit.b4
#define		nch_u3c0	u3c0_addr.bit.b5
#define		ckpol_u3c0	u3c0_addr.bit.b6
#define		uform_u3c0	u3c0_addr.bit.b7

/*------------------------------------------------------
	uart3 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u3c1_addr;
#define		u3c1	u3c1_addr.byte

#define		te_u3c1			u3c1_addr.bit.b0
#define		ti_u3c1			u3c1_addr.bit.b1
#define		re_u3c1			u3c1_addr.bit.b2
#define		ri_u3c1			u3c1_addr.bit.b3
#define		u3irs_u3c1		u3c1_addr.bit.b4
#define		u3rrm_u3c1		u3c1_addr.bit.b5
#define		u3lch_u3c1		u3c1_addr.bit.b6

/*------------------------------------------------------
	uart3 receive buffer Register
------------------------------------------------------*/
union word_def	u3rb_addr;
#define		u3rb	u3rb_addr.word

#define		u3rbl		u3rb_addr.byte.low
#define		u3rbh		u3rb_addr.byte.high

#define		abt_u3rb	u3rb_addr.bit.b11
#define		oer_u3rb	u3rb_addr.bit.b12
#define		fer_u3rb	u3rb_addr.bit.b13
#define		per_u3rb	u3rb_addr.bit.b14
#define		sum_u3rb	u3rb_addr.bit.b15

/*------------------------------------------------------
	uart2 special mode Register 4
------------------------------------------------------*/
union byte_def	u2smr4_addr;
#define		u2smr4	u2smr4_addr.byte

#define		stareq_u2smr4	u2smr4_addr.bit.b0
#define		rstareq_u2smr4	u2smr4_addr.bit.b1
#define		stpreq_u2smr4	u2smr4_addr.bit.b2
#define		stspsel_u2smr4	u2smr4_addr.bit.b3
#define		ackd_u2smr4		u2smr4_addr.bit.b4
#define		ackc_u2smr4		u2smr4_addr.bit.b5
#define		sclhi_u2smr4	u2smr4_addr.bit.b6
#define		swc9_u2smr4		u2smr4_addr.bit.b7

/*------------------------------------------------------
	uart2 special mode Register 3
------------------------------------------------------*/
union byte_def	u2smr3_addr;
#define		u2smr3	u2smr3_addr.byte

#define		sse_u2smr3	u2smr3_addr.bit.b0
#define		ckph_u2smr3	u2smr3_addr.bit.b1
#define		dinc_u2smr3	u2smr3_addr.bit.b2
#define		nodc_u2smr3	u2smr3_addr.bit.b3
#define		err_u2smr3	u2smr3_addr.bit.b4
#define		dl0_u2smr3	u2smr3_addr.bit.b5
#define		dl1_u2smr3	u2smr3_addr.bit.b6
#define		dl2_u2smr3	u2smr3_addr.bit.b7

/*------------------------------------------------------
	uart2 special mode Register 2
------------------------------------------------------*/
union byte_def	u2smr2_addr;
#define		u2smr2	u2smr2_addr.byte

#define		iicm2_u2smr2	u2smr2_addr.bit.b0
#define		csc_u2smr2		u2smr2_addr.bit.b1
#define		swc_u2smr2		u2smr2_addr.bit.b2
#define		als_u2smr2		u2smr2_addr.bit.b3
#define		stc_u2smr2		u2smr2_addr.bit.b4
#define		swc2_u2smr2		u2smr2_addr.bit.b5
#define		sdhi_u2smr2		u2smr2_addr.bit.b6

/*------------------------------------------------------
	uart2 special mode Register
------------------------------------------------------*/
union byte_def	u2smr_addr;
#define		u2smr	u2smr_addr.byte

#define		iicm_u2smr		u2smr_addr.bit.b0
#define		abc_u2smr		u2smr_addr.bit.b1
#define		bbs_u2smr		u2smr_addr.bit.b2
#define		abscs_u2smr		u2smr_addr.bit.b4
#define		acse_u2smr		u2smr_addr.bit.b5
#define		sss_u2smr		u2smr_addr.bit.b6

/*------------------------------------------------------
	uart2 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u2mr_addr;
#define		u2mr	u2mr_addr.byte

#define		smd0_u2mr	u2mr_addr.bit.b0
#define		smd1_u2mr	u2mr_addr.bit.b1
#define		smd2_u2mr	u2mr_addr.bit.b2
#define		ckdir_u2mr	u2mr_addr.bit.b3
#define		stps_u2mr	u2mr_addr.bit.b4
#define		pry_u2mr	u2mr_addr.bit.b5
#define		prye_u2mr	u2mr_addr.bit.b6
#define		iopol_u2mr	u2mr_addr.bit.b7

/*------------------------------------------------------
	uart2 bit rate generator
------------------------------------------------------*/
union byte_def	u2brg_addr;
#define		u2brg	u2brg_addr.byte

/*------------------------------------------------------
	uart2 transmit buffer Register
------------------------------------------------------*/
union word_def	u2tb_addr;
#define		u2tb	u2tb_addr.word

#define		u2tbl	u2tb_addr.byte.low
#define		u2tbh	u2tb_addr.byte.high

/*------------------------------------------------------
	uart2 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u2c0_addr;
#define		u2c0	u2c0_addr.byte

#define		clk0_u2c0	u2c0_addr.bit.b0
#define		clk1_u2c0	u2c0_addr.bit.b1
#define		txept_u2c0	u2c0_addr.bit.b3
#define		crd_u2c0	u2c0_addr.bit.b4
#define		nch_u2c0	u2c0_addr.bit.b5
#define		ckpol_u2c0	u2c0_addr.bit.b6
#define		uform_u2c0	u2c0_addr.bit.b7

/*------------------------------------------------------
	uart2 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u2c1_addr;
#define		u2c1	u2c1_addr.byte

#define		te_u2c1			u2c1_addr.bit.b0
#define		ti_u2c1			u2c1_addr.bit.b1
#define		re_u2c1			u2c1_addr.bit.b2
#define		ri_u2c1			u2c1_addr.bit.b3
#define		u2irs_u2c1		u2c1_addr.bit.b4
#define		u2rrm_u2c1		u2c1_addr.bit.b5
#define		u2lch_u2c1		u2c1_addr.bit.b6

/*------------------------------------------------------
	uart2 receive buffer Register
------------------------------------------------------*/
union word_def	u2rb_addr;
#define		u2rb	u2rb_addr.word

#define		u2rbl		u2rb_addr.byte.low
#define		u2rbh		u2rb_addr.byte.high

#define		abt_u2rb	u2rb_addr.bit.b11
#define		oer_u2rb	u2rb_addr.bit.b12
#define		fer_u2rb	u2rb_addr.bit.b13
#define		per_u2rb	u2rb_addr.bit.b14
#define		sum_u2rb	u2rb_addr.bit.b15

/*------------------------------------------------------
	count start flag
------------------------------------------------------*/
union byte_def	tabsr_addr;
#define		tabsr	tabsr_addr.byte

#define		ta0s	tabsr_addr.bit.b0
#define		ta1s	tabsr_addr.bit.b1
#define		ta2s	tabsr_addr.bit.b2
#define		ta3s	tabsr_addr.bit.b3
#define		ta4s	tabsr_addr.bit.b4
#define		tb0s	tabsr_addr.bit.b5
#define		tb1s	tabsr_addr.bit.b6
#define		tb2s	tabsr_addr.bit.b7

/*------------------------------------------------------
	clock prescaler reset flag
------------------------------------------------------*/
union byte_def	cpsrf_addr;
#define		cpsrf	cpsrf_addr.byte

#define		cpsr	cpsrf_addr.bit.b7

/*------------------------------------------------------
	one shot start flag
------------------------------------------------------*/
union byte_def	onsf_addr;
#define		onsf	onsf_addr.byte

#define		ta0os	onsf_addr.bit.b0
#define		ta1os	onsf_addr.bit.b1
#define		ta2os	onsf_addr.bit.b2
#define		ta3os	onsf_addr.bit.b3
#define		ta4os	onsf_addr.bit.b4
#define		tazie	onsf_addr.bit.b5
#define		ta0tgl	onsf_addr.bit.b6
#define		ta0tgh	onsf_addr.bit.b7

/*------------------------------------------------------
	trigger select Register
------------------------------------------------------*/
union byte_def	trgsr_addr;
#define		trgsr	trgsr_addr.byte

#define		ta1tgl	trgsr_addr.bit.b0
#define		ta1tgh	trgsr_addr.bit.b1
#define		ta2tgl	trgsr_addr.bit.b2
#define		ta2tgh	trgsr_addr.bit.b3
#define		ta3tgl	trgsr_addr.bit.b4
#define		ta3tgh	trgsr_addr.bit.b5
#define		ta4tgl	trgsr_addr.bit.b6
#define		ta4tgh	trgsr_addr.bit.b7

/*------------------------------------------------------
	up down flag
------------------------------------------------------*/
union byte_def	udf_addr;
#define		udf	udf_addr.byte

#define		ta0ud	udf_addr.bit.b0
#define		ta1ud	udf_addr.bit.b1
#define		ta2ud	udf_addr.bit.b2
#define		ta3ud	udf_addr.bit.b3
#define		ta4ud	udf_addr.bit.b4
#define		ta2p	udf_addr.bit.b5
#define		ta3p	udf_addr.bit.b6
#define		ta4p	udf_addr.bit.b7

/*------------------------------------------------------
	timer a0
------------------------------------------------------*/
union word_def	ta0_addr;
#define		ta0	ta0_addr.word

#define		ta0l	ta0_addr.byte.low
#define		ta0h	ta0_addr.byte.high

/*------------------------------------------------------
	timer a1
------------------------------------------------------*/
union word_def	ta1_addr;
#define		ta1	ta1_addr.word

#define		ta1l	ta1_addr.byte.low
#define		ta1h	ta1_addr.byte.high

/*------------------------------------------------------
	timer a2
------------------------------------------------------*/
union word_def	ta2_addr;
#define		ta2	ta2_addr.word

#define		ta2l	ta2_addr.byte.low
#define		ta2h	ta2_addr.byte.high

/*------------------------------------------------------
	timer a3
------------------------------------------------------*/
union word_def	ta3_addr;
#define		ta3	ta3_addr.word

#define		ta3l	ta3_addr.byte.low
#define		ta3h	ta3_addr.byte.high

/*------------------------------------------------------
	timer a4
------------------------------------------------------*/
union word_def	ta4_addr;
#define		ta4	ta4_addr.word

#define		ta4l	ta4_addr.byte.low
#define		ta4h	ta4_addr.byte.high

/*------------------------------------------------------
	timer b0
------------------------------------------------------*/
union word_def	tb0_addr;
#define		tb0	tb0_addr.word

#define		tb0l	tb0_addr.byte.low
#define		tb0h	tb0_addr.byte.high

/*------------------------------------------------------
	timer b1
------------------------------------------------------*/
union word_def	tb1_addr;
#define		tb1	tb1_addr.word

#define		tb1l	tb1_addr.byte.low
#define		tb1h	tb1_addr.byte.high

/*------------------------------------------------------
	timer b2
------------------------------------------------------*/
union word_def	tb2_addr;
#define		tb2	tb2_addr.word

#define		tb2l	tb2_addr.byte.low
#define		tb2h	tb2_addr.byte.high

/*------------------------------------------------------
	timer a0 mode Register
------------------------------------------------------*/
union byte_def	ta0mr_addr;
#define		ta0mr	ta0mr_addr.byte

#define		tmod0_ta0mr	ta0mr_addr.bit.b0
#define		tmod1_ta0mr	ta0mr_addr.bit.b1
#define		mr1_ta0mr	ta0mr_addr.bit.b3
#define		mr2_ta0mr	ta0mr_addr.bit.b4
#define		mr3_ta0mr	ta0mr_addr.bit.b5
#define		tck0_ta0mr	ta0mr_addr.bit.b6
#define		tck1_ta0mr	ta0mr_addr.bit.b7

/*------------------------------------------------------
	timer a1 mode Register
------------------------------------------------------*/
union byte_def	ta1mr_addr;
#define		ta1mr	ta1mr_addr.byte

#define		tmod0_ta1mr	ta1mr_addr.bit.b0
#define		tmod1_ta1mr	ta1mr_addr.bit.b1
#define		mr1_ta1mr	ta1mr_addr.bit.b3
#define		mr2_ta1mr	ta1mr_addr.bit.b4
#define		mr3_ta1mr	ta1mr_addr.bit.b5
#define		tck0_ta1mr	ta1mr_addr.bit.b6
#define		tck1_ta1mr	ta1mr_addr.bit.b7

/*------------------------------------------------------
	timer a2 mode Register
------------------------------------------------------*/
union byte_def	ta2mr_addr;
#define		ta2mr	ta2mr_addr.byte

#define		tmod0_ta2mr	ta2mr_addr.bit.b0
#define		tmod1_ta2mr	ta2mr_addr.bit.b1
#define		mr1_ta2mr	ta2mr_addr.bit.b3
#define		mr2_ta2mr	ta2mr_addr.bit.b4
#define		mr3_ta2mr	ta2mr_addr.bit.b5
#define		tck0_ta2mr	ta2mr_addr.bit.b6
#define		tck1_ta2mr	ta2mr_addr.bit.b7

/*------------------------------------------------------
	timer a3 mode Register
------------------------------------------------------*/
union byte_def	ta3mr_addr;
#define		ta3mr	ta3mr_addr.byte

#define		tmod0_ta3mr	ta3mr_addr.bit.b0
#define		tmod1_ta3mr	ta3mr_addr.bit.b1
#define		mr1_ta3mr	ta3mr_addr.bit.b3
#define		mr2_ta3mr	ta3mr_addr.bit.b4
#define		mr3_ta3mr	ta3mr_addr.bit.b5
#define		tck0_ta3mr	ta3mr_addr.bit.b6
#define		tck1_ta3mr	ta3mr_addr.bit.b7

/*------------------------------------------------------
	timer a4 mode Register
------------------------------------------------------*/
union byte_def	ta4mr_addr;
#define		ta4mr	ta4mr_addr.byte

#define		tmod0_ta4mr	ta4mr_addr.bit.b0
#define		tmod1_ta4mr	ta4mr_addr.bit.b1
#define		mr1_ta4mr	ta4mr_addr.bit.b3
#define		mr2_ta4mr	ta4mr_addr.bit.b4
#define		mr3_ta4mr	ta4mr_addr.bit.b5
#define		tck0_ta4mr	ta4mr_addr.bit.b6
#define		tck1_ta4mr	ta4mr_addr.bit.b7

/*------------------------------------------------------
	timer b0 mode Register
------------------------------------------------------*/
union byte_def	tb0mr_addr;
#define		tb0mr	tb0mr_addr.byte

#define		tmod0_tb0mr	tb0mr_addr.bit.b0
#define		tmod1_tb0mr	tb0mr_addr.bit.b1
#define		mr0_tb0mr	tb0mr_addr.bit.b2
#define		mr1_tb0mr	tb0mr_addr.bit.b3
#define		mr2_tb0mr	tb0mr_addr.bit.b4
#define		mr3_tb0mr	tb0mr_addr.bit.b5
#define		tck0_tb0mr	tb0mr_addr.bit.b6
#define		tck1_tb0mr	tb0mr_addr.bit.b7

/*------------------------------------------------------
	timer b1 mode Register
------------------------------------------------------*/
union byte_def	tb1mr_addr;
#define		tb1mr	tb1mr_addr.byte

#define		tmod0_tb1mr	tb1mr_addr.bit.b0
#define		tmod1_tb1mr	tb1mr_addr.bit.b1
#define		mr0_tb1mr	tb1mr_addr.bit.b2
#define		mr1_tb1mr	tb1mr_addr.bit.b3
#define		mr2_tb1mr	tb1mr_addr.bit.b4
#define		mr3_tb1mr	tb1mr_addr.bit.b5
#define		tck0_tb1mr	tb1mr_addr.bit.b6
#define		tck1_tb1mr	tb1mr_addr.bit.b7

/*------------------------------------------------------
	timer b2 mode Register
------------------------------------------------------*/
union byte_def	tb2mr_addr;
#define		tb2mr	tb2mr_addr.byte

#define		tmod0_tb2mr	tb2mr_addr.bit.b0
#define		tmod1_tb2mr	tb2mr_addr.bit.b1
#define		mr0_tb2mr	tb2mr_addr.bit.b2
#define		mr1_tb2mr	tb2mr_addr.bit.b3
#define		mr2_tb2mr	tb2mr_addr.bit.b4
#define		mr3_tb2mr	tb2mr_addr.bit.b5
#define		tck0_tb2mr	tb2mr_addr.bit.b6
#define		tck1_tb2mr	tb2mr_addr.bit.b7

/*------------------------------------------------------
	timer b2 special mode Register
------------------------------------------------------*/
union byte_def	tb2sc_addr;
#define		tb2sc	tb2sc_addr.byte

#define		pwcon_tb2sc		tb2sc_addr.bit.b0
/*------------------------------------------------------
	timer count source prescaler Register
------------------------------------------------------*/
union byte_def	tcspr_addr;
#define		tcspr	tcspr_addr.byte

#define		cnt0_tcspr	tcspr_addr.bit.b0
#define		cnt1_tcspr	tcspr_addr.bit.b1
#define		cnt2_tcspr	tcspr_addr.bit.b2
#define		cnt3_tcspr	tcspr_addr.bit.b3
#define		cst_tcspr	tcspr_addr.bit.b7

/*------------------------------------------------------
	uart0 special mode Register 4
------------------------------------------------------*/
union byte_def	u0smr4_addr;
#define		u0smr4	u0smr4_addr.byte

#define		stareq_u0smr4	u0smr4_addr.bit.b0
#define		rstareq_u0smr4	u0smr4_addr.bit.b1
#define		stpreq_u0smr4	u0smr4_addr.bit.b2
#define		stspsel_u0smr4	u0smr4_addr.bit.b3
#define		ackd_u0smr4		u0smr4_addr.bit.b4
#define		ackc_u0smr4		u0smr4_addr.bit.b5
#define		sclhi_u0smr4	u0smr4_addr.bit.b6
#define		swc9_u0smr4		u0smr4_addr.bit.b7

/*------------------------------------------------------
	uart0 special mode Register 3
------------------------------------------------------*/
union byte_def	u0smr3_addr;
#define		u0smr3	u0smr3_addr.byte

#define		sse_u0smr3	u0smr3_addr.bit.b0
#define		ckph_u0smr3	u0smr3_addr.bit.b1
#define		dinc_u0smr3	u0smr3_addr.bit.b2
#define		nodc_u0smr3	u0smr3_addr.bit.b3
#define		err_u0smr3	u0smr3_addr.bit.b4
#define		dl0_u0smr3	u0smr3_addr.bit.b5
#define		dl1_u0smr3	u0smr3_addr.bit.b6
#define		dl2_u0smr3	u0smr3_addr.bit.b7

/*------------------------------------------------------
	uart0 special mode Register 2
------------------------------------------------------*/
union byte_def	u0smr2_addr;
#define		u0smr2	u0smr2_addr.byte

#define		iicm2_u0smr2	u0smr2_addr.bit.b0
#define		csc_u0smr2		u0smr2_addr.bit.b1
#define		swc_u0smr2		u0smr2_addr.bit.b2
#define		als_u0smr2		u0smr2_addr.bit.b3
#define		stc_u0smr2		u0smr2_addr.bit.b4
#define		swc2_u0smr2		u0smr2_addr.bit.b5
#define		sdhi_u0smr2		u0smr2_addr.bit.b6

/*------------------------------------------------------
	uart0 special mode Register
------------------------------------------------------*/
union byte_def	u0smr_addr;
#define		u0smr	u0smr_addr.byte

#define		iicm_u0smr		u0smr_addr.bit.b0
#define		abc_u0smr		u0smr_addr.bit.b1
#define		bbs_u0smr		u0smr_addr.bit.b2
#define		abscs_u0smr		u0smr_addr.bit.b4
#define		acse_u0smr		u0smr_addr.bit.b5
#define		sss_u0smr		u0smr_addr.bit.b6

/*------------------------------------------------------
	uart0 transmit receive mode Register
------------------------------------------------------*/
union byte_def	u0mr_addr;
#define		u0mr	u0mr_addr.byte

#define		smd0_u0mr	u0mr_addr.bit.b0
#define		smd1_u0mr	u0mr_addr.bit.b1
#define		smd2_u0mr	u0mr_addr.bit.b2
#define		ckdir_u0mr	u0mr_addr.bit.b3
#define		stps_u0mr	u0mr_addr.bit.b4
#define		pry_u0mr	u0mr_addr.bit.b5
#define		prye_u0mr	u0mr_addr.bit.b6
#define		iopol_u0mr	u0mr_addr.bit.b7

/*------------------------------------------------------
	uart0 bit rate generator
------------------------------------------------------*/
union byte_def	u0brg_addr;
#define		u0brg	u0brg_addr.byte

/*------------------------------------------------------
	uart0 transmit buffer Register
------------------------------------------------------*/
union word_def	u0tb_addr;
#define		u0tb	u0tb_addr.word

#define		u0tbl	u0tb_addr.byte.low
#define		u0tbh	u0tb_addr.byte.high

/*------------------------------------------------------
	uart0 transmit receive Control Register 0
------------------------------------------------------*/
union byte_def	u0c0_addr;
#define		u0c0	u0c0_addr.byte

#define		clk0_u0c0	u0c0_addr.bit.b0
#define		clk1_u0c0	u0c0_addr.bit.b1
#define		txept_u0c0	u0c0_addr.bit.b3
#define		crd_u0c0	u0c0_addr.bit.b4
#define		nch_u0c0	u0c0_addr.bit.b5
#define		ckpol_u0c0	u0c0_addr.bit.b6
#define		uform_u0c0	u0c0_addr.bit.b7

/*------------------------------------------------------
	uart0 transmit receive Control Register 1
------------------------------------------------------*/
union byte_def	u0c1_addr;
#define		u0c1	u0c1_addr.byte

#define		te_u0c1			u0c1_addr.bit.b0
#define		ti_u0c1			u0c1_addr.bit.b1
#define		re_u0c1			u0c1_addr.bit.b2
#define		ri_u0c1			u0c1_addr.bit.b3
#define		u0irs_u0c1		u0c1_addr.bit.b4
#define		u0rrm_u0c1		u0c1_addr.bit.b5
#define		u0lch_u0c1		u0c1_addr.bit.b6

/*------------------------------------------------------
	uart0 receive buffer Register
------------------------------------------------------*/
union word_def	u0rb_addr;
#define		u0rb	u0rb_addr.word

#define		u0rbl		u0rb_addr.byte.low
#define		u0rbh		u0rb_addr.byte.high

#define		abt_u0rb	u0rb_addr.bit.b11
#define		oer_u0rb	u0rb_addr.bit.b12
#define		fer_u0rb	u0rb_addr.bit.b13
#define		per_u0rb	u0rb_addr.bit.b14
#define		sum_u0rb	u0rb_addr.bit.b15

/*------------------------------------------------------
	crc data Register
------------------------------------------------------*/
union word_def	crcd_addr;
#define		crcd	crcd_addr.word

#define		crcdl	crcd_addr.byte.low
#define		crcdh	crcd_addr.byte.high

/*------------------------------------------------------
	crc input Register
------------------------------------------------------*/
union byte_def	crcin_addr;
#define		crcin	crcin_addr.byte

/*------------------------------------------------------
	a-d0 Register 0
------------------------------------------------------*/
union word_def	ad00_addr;
#define		ad00	ad00_addr.word

#define		ad00l	ad00_addr.byte.low
#define		ad00h	ad00_addr.byte.high

/*------------------------------------------------------
	a-d0 Register 1
------------------------------------------------------*/
union word_def	ad01_addr;
#define		ad01	ad01_addr.word

#define		ad01l	ad01_addr.byte.low
#define		ad01h	ad01_addr.byte.high

/*------------------------------------------------------
	a-d0 Register 2
------------------------------------------------------*/
union word_def	ad02_addr;
#define		ad02	ad02_addr.word

#define		ad02l	ad02_addr.byte.low
#define		ad02h	ad02_addr.byte.high

/*------------------------------------------------------
	a-d0 Register 3
------------------------------------------------------*/
union word_def	ad03_addr;
#define		ad03	ad03_addr.word

#define		ad03l	ad03_addr.byte.low
#define		ad03h	ad03_addr.byte.high

/*------------------------------------------------------
	a-d0 Register 4
------------------------------------------------------*/
union word_def	ad04_addr;
#define		ad04	ad04_addr.word

#define		ad04l	ad04_addr.byte.low
#define		ad04h	ad04_addr.byte.high

/*------------------------------------------------------
	a-d0 Register 5
------------------------------------------------------*/
union word_def	ad05_addr;
#define		ad05	ad05_addr.word

#define		ad05l	ad05_addr.byte.low
#define		ad05h	ad05_addr.byte.high

/*------------------------------------------------------
	a-d0 Register 6
------------------------------------------------------*/
union word_def	ad06_addr;
#define		ad06	ad06_addr.word

#define		ad06l	ad06_addr.byte.low
#define		ad06h	ad06_addr.byte.high

/*------------------------------------------------------
	a-d0 Register 7
------------------------------------------------------*/
union word_def	ad07_addr;
#define		ad07	ad07_addr.word

#define		ad07l	ad07_addr.byte.low
#define		ad07h	ad07_addr.byte.high

/*------------------------------------------------------
	a-d0 Control Register 4
------------------------------------------------------*/
union byte_def	ad0con4_addr;
#define		ad0con4	ad0con4_addr.byte

#define		mps10_ad0con4	ad0con4_addr.bit.b2
#define		mps11_ad0con4	ad0con4_addr.bit.b3

/*------------------------------------------------------
	a-d0 Control Register 2
------------------------------------------------------*/
union byte_def	ad0con2_addr;
#define		ad0con2	ad0con2_addr.byte

#define		smp_ad0con2		ad0con2_addr.bit.b0
#define		aps0_ad0con2	ad0con2_addr.bit.b1
#define		aps1_ad0con2	ad0con2_addr.bit.b2
#define		trg0_ad0con2	ad0con2_addr.bit.b5

/*------------------------------------------------------
	a-d0 Control Register 3
------------------------------------------------------*/
union byte_def	ad0con3_addr;
#define		ad0con3	ad0con3_addr.byte

#define		dus_ad0con3		ad0con3_addr.bit.b0
#define		mss_ad0con3		ad0con3_addr.bit.b1
#define		cks2_ad0con3	ad0con3_addr.bit.b2
#define		msf0_ad0con3	ad0con3_addr.bit.b3
#define		msf1_ad0con3	ad0con3_addr.bit.b4

/*------------------------------------------------------
	a-d0 Control Register 0
------------------------------------------------------*/
union byte_def	ad0con0_addr;
#define		ad0con0	ad0con0_addr.byte

#define		ch0_ad0con0		ad0con0_addr.bit.b0
#define		ch1_ad0con0		ad0con0_addr.bit.b1
#define		ch2_ad0con0		ad0con0_addr.bit.b2
#define		md0_ad0con0		ad0con0_addr.bit.b3
#define		md1_ad0con0		ad0con0_addr.bit.b4
#define		trg_ad0con0		ad0con0_addr.bit.b5
#define		adst_ad0con0	ad0con0_addr.bit.b6
#define		cks0_ad0con0	ad0con0_addr.bit.b7

/*------------------------------------------------------
	a-d0 Control Register 1
------------------------------------------------------*/
union byte_def	ad0con1_addr;
#define		ad0con1	ad0con1_addr.byte

#define		scan0_ad0con1	ad0con1_addr.bit.b0
#define		scan1_ad0con1	ad0con1_addr.bit.b1
#define		md2_ad0con1		ad0con1_addr.bit.b2
#define		bits_ad0con1	ad0con1_addr.bit.b3
#define		cks1_ad0con1	ad0con1_addr.bit.b4
#define		vcut_ad0con1	ad0con1_addr.bit.b5
#define		opa0_ad0con1	ad0con1_addr.bit.b6
#define		opa1_ad0con1	ad0con1_addr.bit.b7

/*------------------------------------------------------
	d-a Register 0
------------------------------------------------------*/
union byte_def	da0_addr;
#define		da0	da0_addr.byte

/*------------------------------------------------------
	d-a Register 1
------------------------------------------------------*/
union byte_def	da1_addr;
#define		da1	da1_addr.byte

/*------------------------------------------------------
	d-a Control Register
------------------------------------------------------*/
union byte_def	dacon_addr;
#define		dacon	dacon_addr.byte

#define		da0e	dacon_addr.bit.b0
#define		da1e	dacon_addr.bit.b1

/*------------------------------------------------------
	port p0 Register
------------------------------------------------------*/
union byte_def	p0_addr;
#define		p0	p0_addr.byte

#define		p0_0	p0_addr.bit.b0
#define		p0_1	p0_addr.bit.b1
#define		p0_2	p0_addr.bit.b2
#define		p0_3	p0_addr.bit.b3
#define		p0_4	p0_addr.bit.b4
#define		p0_5	p0_addr.bit.b5
#define		p0_6	p0_addr.bit.b6
#define		p0_7	p0_addr.bit.b7

/*------------------------------------------------------
	port p1 Register
------------------------------------------------------*/
union byte_def	p1_addr;
#define		p1	p1_addr.byte

#define		p1_0	p1_addr.bit.b0
#define		p1_1	p1_addr.bit.b1
#define		p1_2	p1_addr.bit.b2
#define		p1_3	p1_addr.bit.b3
#define		p1_4	p1_addr.bit.b4
#define		p1_5	p1_addr.bit.b5
#define		p1_6	p1_addr.bit.b6
#define		p1_7	p1_addr.bit.b7

/*------------------------------------------------------
	port p0 direction Register
------------------------------------------------------*/
union byte_def	pd0_addr;
#define		pd0	pd0_addr.byte

#define		pd0_0	pd0_addr.bit.b0
#define		pd0_1	pd0_addr.bit.b1
#define		pd0_2	pd0_addr.bit.b2
#define		pd0_3	pd0_addr.bit.b3
#define		pd0_4	pd0_addr.bit.b4
#define		pd0_5	pd0_addr.bit.b5
#define		pd0_6	pd0_addr.bit.b6
#define		pd0_7	pd0_addr.bit.b7

/*------------------------------------------------------
	port p1 direction Register
------------------------------------------------------*/
union byte_def	pd1_addr;
#define		pd1	pd1_addr.byte

#define		pd1_0	pd1_addr.bit.b0
#define		pd1_1	pd1_addr.bit.b1
#define		pd1_2	pd1_addr.bit.b2
#define		pd1_3	pd1_addr.bit.b3
#define		pd1_4	pd1_addr.bit.b4
#define		pd1_5	pd1_addr.bit.b5
#define		pd1_6	pd1_addr.bit.b6
#define		pd1_7	pd1_addr.bit.b7

/*------------------------------------------------------
	port p2 Register
------------------------------------------------------*/
union byte_def	p2_addr;
#define		p2	p2_addr.byte

#define		p2_0	p2_addr.bit.b0
#define		p2_1	p2_addr.bit.b1
#define		p2_2	p2_addr.bit.b2
#define		p2_3	p2_addr.bit.b3
#define		p2_4	p2_addr.bit.b4
#define		p2_5	p2_addr.bit.b5
#define		p2_6	p2_addr.bit.b6
#define		p2_7	p2_addr.bit.b7

/*------------------------------------------------------
	port p3 Register
------------------------------------------------------*/
union byte_def	p3_addr;
#define		p3	p3_addr.byte

#define		p3_0	p3_addr.bit.b0
#define		p3_1	p3_addr.bit.b1
#define		p3_2	p3_addr.bit.b2
#define		p3_3	p3_addr.bit.b3
#define		p3_4	p3_addr.bit.b4
#define		p3_5	p3_addr.bit.b5
#define		p3_6	p3_addr.bit.b6
#define		p3_7	p3_addr.bit.b7

/*------------------------------------------------------
	port p2 direction Register
------------------------------------------------------*/
union byte_def	pd2_addr;
#define		pd2	pd2_addr.byte

#define		pd2_0	pd2_addr.bit.b0
#define		pd2_1	pd2_addr.bit.b1
#define		pd2_2	pd2_addr.bit.b2
#define		pd2_3	pd2_addr.bit.b3
#define		pd2_4	pd2_addr.bit.b4
#define		pd2_5	pd2_addr.bit.b5
#define		pd2_6	pd2_addr.bit.b6
#define		pd2_7	pd2_addr.bit.b7

/*------------------------------------------------------
	port p3 direction Register
------------------------------------------------------*/
union byte_def	pd3_addr;
#define		pd3	pd3_addr.byte

#define		pd3_0	pd3_addr.bit.b0
#define		pd3_1	pd3_addr.bit.b1
#define		pd3_2	pd3_addr.bit.b2
#define		pd3_3	pd3_addr.bit.b3
#define		pd3_4	pd3_addr.bit.b4
#define		pd3_5	pd3_addr.bit.b5
#define		pd3_6	pd3_addr.bit.b6
#define		pd3_7	pd3_addr.bit.b7

/*------------------------------------------------------
	port p4 Register
------------------------------------------------------*/
union byte_def	p4_addr;
#define		p4	p4_addr.byte

#define		p4_0	p4_addr.bit.b0
#define		p4_1	p4_addr.bit.b1
#define		p4_2	p4_addr.bit.b2
#define		p4_3	p4_addr.bit.b3
#define		p4_4	p4_addr.bit.b4
#define		p4_5	p4_addr.bit.b5
#define		p4_6	p4_addr.bit.b6
#define		p4_7	p4_addr.bit.b7

/*------------------------------------------------------
	port p5 Register
------------------------------------------------------*/
union byte_def	p5_addr;
#define		p5	p5_addr.byte

#define		p5_0	p5_addr.bit.b0
#define		p5_1	p5_addr.bit.b1
#define		p5_2	p5_addr.bit.b2
#define		p5_3	p5_addr.bit.b3
#define		p5_4	p5_addr.bit.b4
#define		p5_5	p5_addr.bit.b5
#define		p5_6	p5_addr.bit.b6
#define		p5_7	p5_addr.bit.b7

/*------------------------------------------------------
	port p4 direction Register
------------------------------------------------------*/
union byte_def	pd4_addr;
#define		pd4	pd4_addr.byte

#define		pd4_0	pd4_addr.bit.b0
#define		pd4_1	pd4_addr.bit.b1
#define		pd4_2	pd4_addr.bit.b2
#define		pd4_3	pd4_addr.bit.b3
#define		pd4_4	pd4_addr.bit.b4
#define		pd4_5	pd4_addr.bit.b5
#define		pd4_6	pd4_addr.bit.b6
#define		pd4_7	pd4_addr.bit.b7

/*------------------------------------------------------
	port p5 direction Register
------------------------------------------------------*/
union byte_def	pd5_addr;
#define		pd5	pd5_addr.byte

#define		pd5_0	pd5_addr.bit.b0
#define		pd5_1	pd5_addr.bit.b1
#define		pd5_2	pd5_addr.bit.b2
#define		pd5_3	pd5_addr.bit.b3
#define		pd5_4	pd5_addr.bit.b4
#define		pd5_5	pd5_addr.bit.b5
#define		pd5_6	pd5_addr.bit.b6
#define		pd5_7	pd5_addr.bit.b7

/*------------------------------------------------------
	port p6 Register
------------------------------------------------------*/
union byte_def	p6_addr;
#define		p6	p6_addr.byte

#define		p6_0	p6_addr.bit.b0
#define		p6_1	p6_addr.bit.b1
#define		p6_2	p6_addr.bit.b2
#define		p6_3	p6_addr.bit.b3
#define		p6_4	p6_addr.bit.b4
#define		p6_5	p6_addr.bit.b5
#define		p6_6	p6_addr.bit.b6
#define		p6_7	p6_addr.bit.b7

/*------------------------------------------------------
	port p7 Register
------------------------------------------------------*/
union byte_def	p7_addr;
#define		p7	p7_addr.byte

#define		p7_0	p7_addr.bit.b0
#define		p7_1	p7_addr.bit.b1
#define		p7_2	p7_addr.bit.b2
#define		p7_3	p7_addr.bit.b3
#define		p7_4	p7_addr.bit.b4
#define		p7_5	p7_addr.bit.b5
#define		p7_6	p7_addr.bit.b6
#define		p7_7	p7_addr.bit.b7

/*------------------------------------------------------
	port p6 direction Register
------------------------------------------------------*/
union byte_def	pd6_addr;
#define		pd6	pd6_addr.byte

#define		pd6_0	pd6_addr.bit.b0
#define		pd6_1	pd6_addr.bit.b1
#define		pd6_2	pd6_addr.bit.b2
#define		pd6_3	pd6_addr.bit.b3
#define		pd6_4	pd6_addr.bit.b4
#define		pd6_5	pd6_addr.bit.b5
#define		pd6_6	pd6_addr.bit.b6
#define		pd6_7	pd6_addr.bit.b7

/*------------------------------------------------------
	port p7 direction Register
------------------------------------------------------*/
union byte_def	pd7_addr;
#define		pd7	pd7_addr.byte

#define		pd7_0	pd7_addr.bit.b0
#define		pd7_1	pd7_addr.bit.b1
#define		pd7_2	pd7_addr.bit.b2
#define		pd7_3	pd7_addr.bit.b3
#define		pd7_4	pd7_addr.bit.b4
#define		pd7_5	pd7_addr.bit.b5
#define		pd7_6	pd7_addr.bit.b6
#define		pd7_7	pd7_addr.bit.b7

/*------------------------------------------------------
	port p8 Register
------------------------------------------------------*/
union byte_def	p8_addr;
#define		p8	p8_addr.byte

#define		p8_0	p8_addr.bit.b0
#define		p8_1	p8_addr.bit.b1
#define		p8_2	p8_addr.bit.b2
#define		p8_3	p8_addr.bit.b3
#define		p8_4	p8_addr.bit.b4
#define		p8_5	p8_addr.bit.b5
#define		p8_6	p8_addr.bit.b6
#define		p8_7	p8_addr.bit.b7

/*------------------------------------------------------
	port p9 Register
------------------------------------------------------*/
union byte_def	p9_addr;
#define		p9	p9_addr.byte

#define		p9_1	p9_addr.bit.b1
#define		p9_3	p9_addr.bit.b3
#define		p9_4	p9_addr.bit.b4
#define		p9_5	p9_addr.bit.b5
#define		p9_6	p9_addr.bit.b6
#define		p9_7	p9_addr.bit.b7

/*------------------------------------------------------
	port p8 direction Register
------------------------------------------------------*/
union byte_def	pd8_addr;
#define		pd8	pd8_addr.byte

#define		pd8_0	pd8_addr.bit.b0
#define		pd8_1	pd8_addr.bit.b1
#define		pd8_2	pd8_addr.bit.b2
#define		pd8_3	pd8_addr.bit.b3
#define		pd8_4	pd8_addr.bit.b4
#define		pd8_6	pd8_addr.bit.b6
#define		pd8_7	pd8_addr.bit.b7

/*------------------------------------------------------
	port p9 direction Register
------------------------------------------------------*/
union byte_def	pd9_addr;
#define		pd9	pd9_addr.byte

#define		pd9_3	pd9_addr.bit.b3
#define		pd9_4	pd9_addr.bit.b4
#define		pd9_5	pd9_addr.bit.b5
#define		pd9_6	pd9_addr.bit.b6
#define		pd9_7	pd9_addr.bit.b7

/*------------------------------------------------------
	port p10 Register
------------------------------------------------------*/
union byte_def	p10_addr;
#define		p10	p10_addr.byte

#define		p10_0	p10_addr.bit.b0
#define		p10_1	p10_addr.bit.b1
#define		p10_2	p10_addr.bit.b2
#define		p10_3	p10_addr.bit.b3
#define		p10_4	p10_addr.bit.b4
#define		p10_5	p10_addr.bit.b5
#define		p10_6	p10_addr.bit.b6
#define		p10_7	p10_addr.bit.b7

/*------------------------------------------------------
	port p10 direction Register
------------------------------------------------------*/
union byte_def	pd10_addr;
#define		pd10	pd10_addr.byte

#define		pd10_0	pd10_addr.bit.b0
#define		pd10_1	pd10_addr.bit.b1
#define		pd10_2	pd10_addr.bit.b2
#define		pd10_3	pd10_addr.bit.b3
#define		pd10_4	pd10_addr.bit.b4
#define		pd10_5	pd10_addr.bit.b5
#define		pd10_6	pd10_addr.bit.b6
#define		pd10_7	pd10_addr.bit.b7

/*------------------------------------------------------
	pull-up Control Register 0
------------------------------------------------------*/
union byte_def	pur0_addr;
#define		pur0	pur0_addr.byte

#define		pu00	pur0_addr.bit.b0
#define		pu01	pur0_addr.bit.b1
#define		pu02	pur0_addr.bit.b2
#define		pu03	pur0_addr.bit.b3
#define		pu04	pur0_addr.bit.b4
#define		pu05	pur0_addr.bit.b5
#define		pu06	pur0_addr.bit.b6
#define		pu07	pur0_addr.bit.b7

/*------------------------------------------------------
	pull-up Control Register 1
------------------------------------------------------*/
union byte_def	pur1_addr;
#define		pur1	pur1_addr.byte

#define		pu10	pur1_addr.bit.b0
#define		pu11	pur1_addr.bit.b1
#define		pu12	pur1_addr.bit.b2
#define		pu13	pur1_addr.bit.b3

/*------------------------------------------------------
	pull-up Control Register 2
------------------------------------------------------*/
union byte_def	pur2_addr;
#define		pur2	pur2_addr.byte

#define		pu20	pur2_addr.bit.b0
#define		pu21	pur2_addr.bit.b1
#define		pu22	pur2_addr.bit.b2
#define		pu23	pur2_addr.bit.b3
#define		pu24	pur2_addr.bit.b4
#define		pu25	pur2_addr.bit.b5
#define		pu26	pur2_addr.bit.b6
#define		pu27	pur2_addr.bit.b7

/*------------------------------------------------------
	pull-up Control Register 3
------------------------------------------------------*/
union byte_def	pur3_addr;
#define		pur3	pur3_addr.byte

#define		pu30	pur3_addr.bit.b0
#define		pu31	pur3_addr.bit.b1

/*------------------------------------------------------
	port Control Register
------------------------------------------------------*/
union byte_def	pcr_addr;
#define		pcr	pcr_addr.byte

#define		pcr0	pcr_addr.bit.b0

/*------------------------------------------------------
	Flash Memory Control Register 0
------------------------------------------------------*/
union byte_def	far	fmr0_addr;
#define		fmr0	fmr0_addr.byte

#define		ewm		fmr0_addr.bit.b0
#define		lbm		fmr0_addr.bit.b1
#define		lbs		fmr0_addr.bit.b2
#define		rrdy	fmr0_addr.bit.b3

/*------------------------------------------------------
	Flash Memory Starus Register	0
------------------------------------------------------*/
union byte_def	far	fmsr0_addr;
#define		fmsr0	fmsr0_addr.byte

#define		werr	fmsr0_addr.bit.b4
#define		eerr	fmsr0_addr.bit.b5
#define		rdy		fmsr0_addr.bit.b7

/*------------------------------------------------------
	Flash Register Protect Cancel Register	0
------------------------------------------------------*/
union byte_def	far	fpr0_addr;
#define		fpr0	fpr0_addr.byte

#define		pr0		fpr0_addr.bit.b0

/*------------------------------------------------------
	Flash Memory Control Register 1
------------------------------------------------------*/
union byte_def	far	fmr1_addr;
#define		fmr1	fmr1_addr.byte

#define		rr		fmr1_addr.bit.b1
#define		lbd		fmr1_addr.bit.b3

/*------------------------------------------------------
	Flash Memory Protect Bit Moniter Register 0
------------------------------------------------------*/
union byte_def	far	fbpm0_addr;
#define		fbpm0	fbpm0_addr.byte

#define		bp0		fbpm0_addr.bit.b0
#define		bp1		fbpm0_addr.bit.b1
#define		bp2		fbpm0_addr.bit.b2
#define		bp3		fbpm0_addr.bit.b3
#define		bp4		fbpm0_addr.bit.b4
#define		bp5		fbpm0_addr.bit.b6
#define		bp6		fbpm0_addr.bit.b7

/*------------------------------------------------------
	Flash Memory Protect Bit Moniter Register 1
------------------------------------------------------*/
union byte_def	far	fbpm1_addr;
#define		fbpm1	fbpm1_addr.byte

#define		bp7		fbpm1_addr.bit.b0
#define		bp8		fbpm1_addr.bit.b1
#define		bp9		fbpm1_addr.bit.b2
#define		bpb		fbpm1_addr.bit.b3
#define		bpa		fbpm1_addr.bit.b4

/*------------------------------------------------------
	PLL Control Register 0
------------------------------------------------------*/
union byte_def	far	plc0_addr;
#define		plc0	plc0_addr.byte

#define		mcv0	plc0_addr.bit.b0
#define		mcv1	plc0_addr.bit.b1
#define		mcv2	plc0_addr.bit.b2
#define		mcv3	plc0_addr.bit.b3
#define		mcv4	plc0_addr.bit.b4
#define		scv0	plc0_addr.bit.b5
#define		scv1	plc0_addr.bit.b6
#define		scv2	plc0_addr.bit.b7

/*------------------------------------------------------
	PLL Control Register 1
------------------------------------------------------*/
union byte_def	far	plc1_addr;
#define		plc1	plc1_addr.byte

#define		rcv0	plc1_addr.bit.b0
#define		rcv1	plc1_addr.bit.b1
#define		rcv2	plc1_addr.bit.b2
#define		rcv3	plc1_addr.bit.b3
#define		seo		plc1_addr.bit.b4

/*------------------------------------------------------
	Processer Mode Register
------------------------------------------------------*/
union byte_def	far	pm0_addr;
#define		pm0	pm0_addr.byte

#define		pm00	pm0_addr.bit.b0
#define		pm01	pm0_addr.bit.b1
#define		pm02	pm0_addr.bit.b2
#define		pm03	pm0_addr.bit.b3
#define		pm07	pm0_addr.bit.b7

/*------------------------------------------------------
	Systen Clock Control Register 0
------------------------------------------------------*/
union byte_def	far	cm0_addr;
#define		cm0	cm0_addr.byte

#define		cm00	cm0_addr.bit.b0
#define		cm01	cm0_addr.bit.b1
#define		cm02	cm0_addr.bit.b2
#define		cm03	cm0_addr.bit.b3
#define		cm04	cm0_addr.bit.b4
#define		cm05	cm0_addr.bit.b5
#define		cm06	cm0_addr.bit.b6

/*------------------------------------------------------
	Systen Clock Control Register 1
------------------------------------------------------*/
union byte_def	far	cm1_addr;
#define		cm1	cm1_addr.byte

#define		cm10	cm1_addr.bit.b0
#define		cm15	cm1_addr.bit.b5
#define		cm16	cm1_addr.bit.b6

/*------------------------------------------------------
	Processer Mode Register	3
------------------------------------------------------*/
union byte_def	far	pm3_addr;
#define		pm3	pm3_addr.byte

#define		pm35	pm3_addr.bit.b5
#define		pm36	pm3_addr.bit.b6

/*------------------------------------------------------
	Protect Register
------------------------------------------------------*/
union byte_def	far	prcr_addr;
#define		prcr	prcr_addr.byte

#define		prc0	prcr_addr.bit.b0
#define		prc1	prcr_addr.bit.b1
#define		prc2	prcr_addr.bit.b2

/*------------------------------------------------------
	Protect Register 3
------------------------------------------------------*/
union byte_def	far	prcr3_addr;
#define		prcr3	prcr3_addr.byte

#define		prc31	prcr3_addr.bit.b1

/*------------------------------------------------------
	Systen Clock Control Register 2
------------------------------------------------------*/
union byte_def	far	cm2_addr;
#define		cm2	cm2_addr.byte

#define		cm20	cm2_addr.bit.b0
#define		cm22	cm2_addr.bit.b2
#define		cm23	cm2_addr.bit.b3

/*------------------------------------------------------
	Processer Mode Register	2
------------------------------------------------------*/
union byte_def	far	pm2_addr;
#define		pm2	pm2_addr.byte

#define		pm21	pm2_addr.bit.b1
#define		pm24	pm2_addr.bit.b4
#define		pm26	pm2_addr.bit.b6

/*------------------------------------------------------
	CS Output Pin Setting Register 0
------------------------------------------------------*/
union byte_def	far	csop0_addr;
#define		csop0	csop0_addr.byte

#define		p4_4b	csop0_addr.bit.b4
#define		p4_5b	csop0_addr.bit.b5
#define		p4_6b	csop0_addr.bit.b6
#define		p4_7b	csop0_addr.bit.b7

/*------------------------------------------------------
	CS Output Pin Setting Register 1
------------------------------------------------------*/
union byte_def	far	csop1_addr;
#define		csop1	csop1_addr.byte

#define		p5_4b	csop1_addr.bit.b4
#define		p5_6b	csop1_addr.bit.b6
#define		p5_7b	csop1_addr.bit.b7

/*------------------------------------------------------
Slow Speed Mode Clock Control Register
------------------------------------------------------*/
union byte_def	far	cm3_addr;
#define		cm3		cm3_addr.byte

#define		cm30	cm3_addr.bit.b0
#define		cm31	cm3_addr.bit.b1

/*------------------------------------------------------
	Voltage Regulater Control Register
------------------------------------------------------*/
union byte_def	far	vrcr_addr;
#define		vrcr	vrcr_addr.byte

#define		mrs		vrcr_addr.bit.b0

/*------------------------------------------------------
	Voltage Down Detection Circuit Control Register
------------------------------------------------------*/
union byte_def	far	lvdc_addr;
#define		lvdc	lvdc_addr.byte

#define		vden	lvdc_addr.bit.b0
#define		lvdien	lvdc_addr.bit.b1
#define		lvdf	lvdc_addr.bit.b2
#define		vmf		lvdc_addr.bit.b3

/*------------------------------------------------------
	Detection Voltage Setting Register
------------------------------------------------------*/
union byte_def	far	dvcr_addr;
#define		dvcr	dvcr_addr.byte

#define		rvc0	dvcr_addr.bit.b0
#define		rvc1	dvcr_addr.bit.b1
#define		rvc2	dvcr_addr.bit.b2
#define		rvc3	dvcr_addr.bit.b3

/*------------------------------------------------------
	three phase output buffer Control Register
------------------------------------------------------*/
union byte_def	far	iobc_addr;
#define		iobc	iobc_addr.byte

#define		tbsout	iobc_addr.bit.b7

/*------------------------------------------------------
	Input function select Register 0
------------------------------------------------------*/
union byte_def	far	ifs0_addr;
#define		ifs0	ifs0_addr.byte

#define		ifs00	ifs0_addr.bit.b0

/*------------------------------------------------------
	Input function select Register 2
------------------------------------------------------*/
union byte_def	far	ifs2_addr;
#define		ifs2	ifs2_addr.byte

#define		ifs22	ifs2_addr.bit.b2
#define		ifs23	ifs2_addr.bit.b3
#define		ifs25	ifs2_addr.bit.b5
#define		ifs26	ifs2_addr.bit.b6
#define		ifs27	ifs2_addr.bit.b7

/*------------------------------------------------------
	Input function select Register 3
------------------------------------------------------*/
union byte_def	far	ifs3_addr;
#define		ifs3	ifs3_addr.byte

#define		ifs30	ifs3_addr.bit.b0
#define		ifs31	ifs3_addr.bit.b1

/*------------------------------------------------------
	Port P0_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p0_0s_addr;
#define		p0_0s	p0_0s_addr.byte

#define		psel0_p0_0s	p0_0s_addr.bit.b0
#define		psel1_p0_0s	p0_0s_addr.bit.b1
#define		psel2_p0_0s	p0_0s_addr.bit.b2
#define		asel_p0_0s	p0_0s_addr.bit.b7

/*------------------------------------------------------
	Port P1_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p1_0s_addr;
#define		p1_0s	p1_0s_addr.byte

#define		psel0_p1_0s	p1_0s_addr.bit.b0
#define		psel1_p1_0s	p1_0s_addr.bit.b1
#define		psel2_p1_0s	p1_0s_addr.bit.b2

/*------------------------------------------------------
	Port P0_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p0_1s_addr;
#define		p0_1s	p0_1s_addr.byte

#define		psel0_p0_1s	p0_1s_addr.bit.b0
#define		psel1_p0_1s	p0_1s_addr.bit.b1
#define		psel2_p0_1s	p0_1s_addr.bit.b2
#define		asel_p0_1s	p0_1s_addr.bit.b7

/*------------------------------------------------------
	Port P1_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p1_1s_addr;
#define		p1_1s	p1_1s_addr.byte

#define		psel0_p1_1s	p1_1s_addr.bit.b0
#define		psel1_p1_1s	p1_1s_addr.bit.b1
#define		psel2_p1_1s	p1_1s_addr.bit.b2

/*------------------------------------------------------
	Port P0_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p0_2s_addr;
#define		p0_2s	p0_2s_addr.byte

#define		psel0_p0_2s	p0_2s_addr.bit.b0
#define		psel1_p0_2s	p0_2s_addr.bit.b1
#define		psel2_p0_2s	p0_2s_addr.bit.b2
#define		asel_p0_2s	p0_2s_addr.bit.b7

/*------------------------------------------------------
	Port P1_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p1_2s_addr;
#define		p1_2s	p1_2s_addr.byte

#define		psel0_p1_2s	p1_2s_addr.bit.b0
#define		psel1_p1_2s	p1_2s_addr.bit.b1
#define		psel2_p1_2s	p1_2s_addr.bit.b2

/*------------------------------------------------------
	Port P0_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p0_3s_addr;
#define		p0_3s	p0_3s_addr.byte

#define		psel0_p0_3s	p0_3s_addr.bit.b0
#define		psel1_p0_3s	p0_3s_addr.bit.b1
#define		psel2_p0_3s	p0_3s_addr.bit.b2
#define		asel_p0_3s	p0_3s_addr.bit.b7

/*------------------------------------------------------
	Port P1_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p1_3s_addr;
#define		p1_3s	p1_3s_addr.byte

#define		psel0_p1_3s	p1_3s_addr.bit.b0
#define		psel1_p1_3s	p1_3s_addr.bit.b1
#define		psel2_p1_3s	p1_3s_addr.bit.b2

/*------------------------------------------------------
	Port P0_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p0_4s_addr;
#define		p0_4s	p0_4s_addr.byte

#define		psel0_p0_4s	p0_4s_addr.bit.b0
#define		psel1_p0_4s	p0_4s_addr.bit.b1
#define		psel2_p0_4s	p0_4s_addr.bit.b2
#define		asel_p0_4s	p0_4s_addr.bit.b7

/*------------------------------------------------------
	Port P1_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p1_4s_addr;
#define		p1_4s	p1_4s_addr.byte

#define		psel0_p1_4s	p1_4s_addr.bit.b0
#define		psel1_p1_4s	p1_4s_addr.bit.b1
#define		psel2_p1_4s	p1_4s_addr.bit.b2

/*------------------------------------------------------
	Port P0_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p0_5s_addr;
#define		p0_5s	p0_5s_addr.byte

#define		psel0_p0_5s	p0_5s_addr.bit.b0
#define		psel1_p0_5s	p0_5s_addr.bit.b1
#define		psel2_p0_5s	p0_5s_addr.bit.b2
#define		asel_p0_5s	p0_5s_addr.bit.b7

/*------------------------------------------------------
	Port P1_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p1_5s_addr;
#define		p1_5s	p1_5s_addr.byte

#define		psel0_p1_5s	p1_5s_addr.bit.b0
#define		psel1_p1_5s	p1_5s_addr.bit.b1
#define		psel2_p1_5s	p1_5s_addr.bit.b2

/*------------------------------------------------------
	Port P0_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p0_6s_addr;
#define		p0_6s	p0_6s_addr.byte

#define		psel0_p0_6s	p0_6s_addr.bit.b0
#define		psel1_p0_6s	p0_6s_addr.bit.b1
#define		psel2_p0_6s	p0_6s_addr.bit.b2
#define		asel_p0_6s	p0_6s_addr.bit.b7

/*------------------------------------------------------
	Port P1_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p1_6s_addr;
#define		p1_6s	p1_6s_addr.byte

#define		psel0_p1_6s	p1_6s_addr.bit.b0
#define		psel1_p1_6s	p1_6s_addr.bit.b1
#define		psel2_p1_6s	p1_6s_addr.bit.b2

/*------------------------------------------------------
	Port P0_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p0_7s_addr;
#define		p0_7s	p0_7s_addr.byte

#define		psel0_p0_7s	p0_7s_addr.bit.b0
#define		psel1_p0_7s	p0_7s_addr.bit.b1
#define		psel2_p0_7s	p0_7s_addr.bit.b2
#define		asel_p0_7s	p0_7s_addr.bit.b7
/*------------------------------------------------------
	Port P1_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p1_7s_addr;
#define		p1_7s	p1_7s_addr.byte

#define		psel0_p1_7s	p1_7s_addr.bit.b0
#define		psel1_p1_7s	p1_7s_addr.bit.b1
#define		psel2_p1_7s	p1_7s_addr.bit.b2

/*------------------------------------------------------
	Port P2_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p2_0s_addr;
#define		p2_0s	p2_0s_addr.byte

#define		psel0_p2_0s	p2_0s_addr.bit.b0
#define		psel1_p2_0s	p2_0s_addr.bit.b1
#define		psel2_p2_0s	p2_0s_addr.bit.b2
#define		asel_p2_0s	p2_0s_addr.bit.b7

/*------------------------------------------------------
	Port P3_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p3_0s_addr;
#define		p3_0s	p3_0s_addr.byte

#define		psel0_p3_0s	p3_0s_addr.bit.b0
#define		psel1_p3_0s	p3_0s_addr.bit.b1
#define		psel2_p3_0s	p3_0s_addr.bit.b2

/*------------------------------------------------------
	Port P2_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p2_1s_addr;
#define		p2_1s	p2_1s_addr.byte

#define		psel0_p2_1s	p2_1s_addr.bit.b0
#define		psel1_p2_1s	p2_1s_addr.bit.b1
#define		psel2_p2_1s	p2_1s_addr.bit.b2
#define		asel_p2_1s	p2_1s_addr.bit.b7

/*------------------------------------------------------
	Port P3_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p3_1s_addr;
#define		p3_1s	p3_1s_addr.byte

#define		psel0_p3_1s	p3_1s_addr.bit.b0
#define		psel1_p3_1s	p3_1s_addr.bit.b1
#define		psel2_p3_1s	p3_1s_addr.bit.b2

/*------------------------------------------------------
	Port P2_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p2_2s_addr;
#define		p2_2s	p2_2s_addr.byte

#define		psel0_p2_2s	p2_2s_addr.bit.b0
#define		psel1_p2_2s	p2_2s_addr.bit.b1
#define		psel2_p2_2s	p2_2s_addr.bit.b2
#define		asel_p2_2s	p2_2s_addr.bit.b7

/*------------------------------------------------------
	Port P3_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p3_2s_addr;
#define		p3_2s	p3_2s_addr.byte

#define		psel0_p3_2s	p3_2s_addr.bit.b0
#define		psel1_p3_2s	p3_2s_addr.bit.b1
#define		psel2_p3_2s	p3_2s_addr.bit.b2

/*------------------------------------------------------
	Port P2_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p2_3s_addr;
#define		p2_3s	p2_3s_addr.byte

#define		psel0_p2_3s	p2_3s_addr.bit.b0
#define		psel1_p2_3s	p2_3s_addr.bit.b1
#define		psel2_p2_3s	p2_3s_addr.bit.b2
#define		asel_p2_3s	p2_3s_addr.bit.b7

/*------------------------------------------------------
	Port P3_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p3_3s_addr;
#define		p3_3s	p3_3s_addr.byte

#define		psel0_p3_3s	p3_3s_addr.bit.b0
#define		psel1_p3_3s	p3_3s_addr.bit.b1
#define		psel2_p3_3s	p3_3s_addr.bit.b2

/*------------------------------------------------------
	Port P2_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p2_4s_addr;
#define		p2_4s	p2_4s_addr.byte

#define		psel0_p2_4s	p2_4s_addr.bit.b0
#define		psel1_p2_4s	p2_4s_addr.bit.b1
#define		psel2_p2_4s	p2_4s_addr.bit.b2
#define		asel_p2_4s	p2_4s_addr.bit.b7

/*------------------------------------------------------
	Port P3_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p3_4s_addr;
#define		p3_4s	p3_4s_addr.byte

#define		psel0_p3_4s	p3_4s_addr.bit.b0
#define		psel1_p3_4s	p3_4s_addr.bit.b1
#define		psel2_p3_4s	p3_4s_addr.bit.b2

/*------------------------------------------------------
	Port P2_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p2_5s_addr;
#define		p2_5s	p2_5s_addr.byte

#define		psel0_p2_5s	p2_5s_addr.bit.b0
#define		psel1_p2_5s	p2_5s_addr.bit.b1
#define		psel2_p2_5s	p2_5s_addr.bit.b2
#define		asel_p2_5s	p2_5s_addr.bit.b7

/*------------------------------------------------------
	Port P3_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p3_5s_addr;
#define		p3_5s	p3_5s_addr.byte

#define		psel0_p3_5s	p3_5s_addr.bit.b0
#define		psel1_p3_5s	p3_5s_addr.bit.b1
#define		psel2_p3_5s	p3_5s_addr.bit.b2

/*------------------------------------------------------
	Port P2_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p2_6s_addr;
#define		p2_6s	p2_6s_addr.byte

#define		psel0_p2_6s	p2_6s_addr.bit.b0
#define		psel1_p2_6s	p2_6s_addr.bit.b1
#define		psel2_p2_6s	p2_6s_addr.bit.b2
#define		asel_p2_6s	p2_6s_addr.bit.b7

/*------------------------------------------------------
	Port P3_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p3_6s_addr;
#define		p3_6s	p3_6s_addr.byte

#define		psel0_p3_6s	p3_6s_addr.bit.b0
#define		psel1_p3_6s	p3_6s_addr.bit.b1
#define		psel2_p3_6s	p3_6s_addr.bit.b2

/*------------------------------------------------------
	Port P2_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p2_7s_addr;
#define		p2_7s	p2_7s_addr.byte

#define		psel0_p2_7s	p2_7s_addr.bit.b0
#define		psel1_p2_7s	p2_7s_addr.bit.b1
#define		psel2_p2_7s	p2_7s_addr.bit.b2
#define		asel_p2_7s	p2_7s_addr.bit.b7

/*------------------------------------------------------
	Port P3_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p3_7s_addr;
#define		p3_7s	p3_7s_addr.byte

#define		psel0_p3_7s	p3_7s_addr.bit.b0
#define		psel1_p3_7s	p3_7s_addr.bit.b1
#define		psel2_p3_7s	p3_7s_addr.bit.b2

/*------------------------------------------------------
	Port P4_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p4_0s_addr;
#define		p4_0s	p4_0s_addr.byte

#define		psel0_p4_0s	p4_0s_addr.bit.b0
#define		psel1_p4_0s	p4_0s_addr.bit.b1
#define		psel2_p4_0s	p4_0s_addr.bit.b2

/*------------------------------------------------------
	Port P5_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p5_0s_addr;
#define		p5_0s	p5_0s_addr.byte

#define		psel0_p5_0s	p5_0s_addr.bit.b0
#define		psel1_p5_0s	p5_0s_addr.bit.b1
#define		psel2_p5_0s	p5_0s_addr.bit.b2

/*------------------------------------------------------
	Port P4_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p4_1s_addr;
#define		p4_1s	p4_1s_addr.byte

#define		psel0_p4_1s	p4_1s_addr.bit.b0
#define		psel1_p4_1s	p4_1s_addr.bit.b1
#define		psel2_p4_1s	p4_1s_addr.bit.b2

/*------------------------------------------------------
	Port P5_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p5_1s_addr;
#define		p5_1s	p5_1s_addr.byte

#define		psel0_p5_1s	p5_1s_addr.bit.b0
#define		psel1_p5_1s	p5_1s_addr.bit.b1
#define		psel2_p5_1s	p5_1s_addr.bit.b2

/*------------------------------------------------------
	Port P4_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p4_2s_addr;
#define		p4_2s	p4_2s_addr.byte

#define		psel0_p4_2s	p4_2s_addr.bit.b0
#define		psel1_p4_2s	p4_2s_addr.bit.b1
#define		psel2_p4_2s	p4_2s_addr.bit.b2

/*------------------------------------------------------
	Port P5_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p5_2s_addr;
#define		p5_2s	p5_2s_addr.byte

#define		psel0_p5_2s	p5_2s_addr.bit.b0
#define		psel1_p5_2s	p5_2s_addr.bit.b1
#define		psel2_p5_2s	p5_2s_addr.bit.b2

/*------------------------------------------------------
	Port P4_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p4_3s_addr;
#define		p4_3s	p4_3s_addr.byte

#define		psel0_p4_3s	p4_3s_addr.bit.b0
#define		psel1_p4_3s	p4_3s_addr.bit.b1
#define		psel2_p4_3s	p4_3s_addr.bit.b2

/*------------------------------------------------------
	Port P5_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p5_3s_addr;
#define		p5_3s	p5_3s_addr.byte

#define		psel0_p5_3s	p5_3s_addr.bit.b0
#define		psel1_p5_3s	p5_3s_addr.bit.b1
#define		psel2_p5_3s	p5_3s_addr.bit.b2

/*------------------------------------------------------
	Port P4_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p4_4s_addr;
#define		p4_4s	p4_4s_addr.byte

#define		psel0_p4_4s	p4_4s_addr.bit.b0
#define		psel1_p4_4s	p4_4s_addr.bit.b1
#define		psel2_p4_4s	p4_4s_addr.bit.b2

/*------------------------------------------------------
	Port P5_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p5_4s_addr;
#define		p5_4s	p5_4s_addr.byte

#define		psel0_p5_4s	p5_4s_addr.bit.b0
#define		psel1_p5_4s	p5_4s_addr.bit.b1
#define		psel2_p5_4s	p5_4s_addr.bit.b2

/*------------------------------------------------------
	Port P4_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p4_5s_addr;
#define		p4_5s	p4_5s_addr.byte

#define		psel0_p4_5s	p4_5s_addr.bit.b0
#define		psel1_p4_5s	p4_5s_addr.bit.b1
#define		psel2_p4_5s	p4_5s_addr.bit.b2

/*------------------------------------------------------
	Port P5_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p5_5s_addr;
#define		p5_5s	p5_5s_addr.byte

#define		psel0_p5_5s	p5_5s_addr.bit.b0
#define		psel1_p5_5s	p5_5s_addr.bit.b1
#define		psel2_p5_5s	p5_5s_addr.bit.b2

/*------------------------------------------------------
	Port P4_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p4_6s_addr;
#define		p4_6s	p4_6s_addr.byte

#define		psel0_p4_6s	p4_6s_addr.bit.b0
#define		psel1_p4_6s	p4_6s_addr.bit.b1
#define		psel2_p4_6s	p4_6s_addr.bit.b2

/*------------------------------------------------------
	Port P5_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p5_6s_addr;
#define		p5_6s	p5_6s_addr.byte

#define		psel0_p5_6s	p5_6s_addr.bit.b0
#define		psel1_p5_6s	p5_6s_addr.bit.b1
#define		psel2_p5_6s	p5_6s_addr.bit.b2

/*------------------------------------------------------
	Port P4_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p4_7s_addr;
#define		p4_7s	p4_7s_addr.byte

#define		psel0_p4_7s	p4_7s_addr.bit.b0
#define		psel1_p4_7s	p4_7s_addr.bit.b1
#define		psel2_p4_7s	p4_7s_addr.bit.b2

/*------------------------------------------------------
	Port P5_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p5_7s_addr;
#define		p5_7s	p5_7s_addr.byte

#define		psel0_p5_7s	p5_7s_addr.bit.b0
#define		psel1_p5_7s	p5_7s_addr.bit.b1
#define		psel2_p5_7s	p5_7s_addr.bit.b2

/*------------------------------------------------------
	Port P6_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p6_0s_addr;
#define		p6_0s	p6_0s_addr.byte

#define		psel0_p6_0s	p6_0s_addr.bit.b0
#define		psel1_p6_0s	p6_0s_addr.bit.b1
#define		psel2_p6_0s	p6_0s_addr.bit.b2

/*------------------------------------------------------
	Port P7_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p7_0s_addr;
#define		p7_0s	p7_0s_addr.byte

#define		psel0_p7_0s	p7_0s_addr.bit.b0
#define		psel1_p7_0s	p7_0s_addr.bit.b1
#define		psel2_p7_0s	p7_0s_addr.bit.b2

/*------------------------------------------------------
	Port P6_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p6_1s_addr;
#define		p6_1s	p6_1s_addr.byte

#define		psel0_p6_1s	p6_1s_addr.bit.b0
#define		psel1_p6_1s	p6_1s_addr.bit.b1
#define		psel2_p6_1s	p6_1s_addr.bit.b2

/*------------------------------------------------------
	Port P7_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p7_1s_addr;
#define		p7_1s	p7_1s_addr.byte

#define		psel0_p7_1s	p7_1s_addr.bit.b0
#define		psel1_p7_1s	p7_1s_addr.bit.b1
#define		psel2_p7_1s	p7_1s_addr.bit.b2

/*------------------------------------------------------
	Port P6_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p6_2s_addr;
#define		p6_2s	p6_2s_addr.byte

#define		psel0_p6_2s	p6_2s_addr.bit.b0
#define		psel1_p6_2s	p6_2s_addr.bit.b1
#define		psel2_p6_2s	p6_2s_addr.bit.b2

/*------------------------------------------------------
	Port P7_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p7_2s_addr;
#define		p7_2s	p7_2s_addr.byte

#define		psel0_p7_2s	p7_2s_addr.bit.b0
#define		psel1_p7_2s	p7_2s_addr.bit.b1
#define		psel2_p7_2s	p7_2s_addr.bit.b2

/*------------------------------------------------------
	Port P6_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p6_3s_addr;
#define		p6_3s	p6_3s_addr.byte

#define		psel0_p6_3s	p6_3s_addr.bit.b0
#define		psel1_p6_3s	p6_3s_addr.bit.b1
#define		psel2_p6_3s	p6_3s_addr.bit.b2

/*------------------------------------------------------
	Port P7_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p7_3s_addr;
#define		p7_3s	p7_3s_addr.byte

#define		psel0_p7_3s	p7_3s_addr.bit.b0
#define		psel1_p7_3s	p7_3s_addr.bit.b1
#define		psel2_p7_3s	p7_3s_addr.bit.b2

/*------------------------------------------------------
	Port P6_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p6_4s_addr;
#define		p6_4s	p6_4s_addr.byte

#define		psel0_p6_4s	p6_4s_addr.bit.b0
#define		psel1_p6_4s	p6_4s_addr.bit.b1
#define		psel2_p6_4s	p6_4s_addr.bit.b2

/*------------------------------------------------------
	Port P7_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p7_4s_addr;
#define		p7_4s	p7_4s_addr.byte

#define		psel0_p7_4s	p7_4s_addr.bit.b0
#define		psel1_p7_4s	p7_4s_addr.bit.b1
#define		psel2_p7_4s	p7_4s_addr.bit.b2

/*------------------------------------------------------
	Port P6_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p6_5s_addr;
#define		p6_5s	p6_5s_addr.byte

#define		psel0_p6_5s	p6_5s_addr.bit.b0
#define		psel1_p6_5s	p6_5s_addr.bit.b1
#define		psel2_p6_5s	p6_5s_addr.bit.b2

/*------------------------------------------------------
	Port P7_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p7_5s_addr;
#define		p7_5s	p7_5s_addr.byte

#define		psel0_p7_5s	p7_5s_addr.bit.b0
#define		psel1_p7_5s	p7_5s_addr.bit.b1
#define		psel2_p7_5s	p7_5s_addr.bit.b2

/*------------------------------------------------------
	Port P6_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p6_6s_addr;
#define		p6_6s	p6_6s_addr.byte

#define		psel0_p6_6s	p6_6s_addr.bit.b0
#define		psel1_p6_6s	p6_6s_addr.bit.b1
#define		psel2_p6_6s	p6_6s_addr.bit.b2

/*------------------------------------------------------
	Port P7_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p7_6s_addr;
#define		p7_6s	p7_6s_addr.byte

#define		psel0_p7_6s	p7_6s_addr.bit.b0
#define		psel1_p7_6s	p7_6s_addr.bit.b1
#define		psel2_p7_6s	p7_6s_addr.bit.b2

/*------------------------------------------------------
	Port P6_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p6_7s_addr;
#define		p6_7s	p6_7s_addr.byte

#define		psel0_p6_7s	p6_7s_addr.bit.b0
#define		psel1_p6_7s	p6_7s_addr.bit.b1
#define		psel2_p6_7s	p6_7s_addr.bit.b2

/*------------------------------------------------------
	Port P7_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p7_7s_addr;
#define		p7_7s	p7_7s_addr.byte

#define		psel0_p7_7s	p7_7s_addr.bit.b0
#define		psel1_p7_7s	p7_7s_addr.bit.b1
#define		psel2_p7_7s	p7_7s_addr.bit.b2

/*------------------------------------------------------
	Port P8_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p8_0s_addr;
#define		p8_0s	p8_0s_addr.byte

#define		psel0_p8_0s	p8_0s_addr.bit.b0
#define		psel1_p8_0s	p8_0s_addr.bit.b1
#define		psel2_p8_0s	p8_0s_addr.bit.b2

/*------------------------------------------------------
	Port P8_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p8_1s_addr;
#define		p8_1s	p8_1s_addr.byte

#define		psel0_p8_1s	p8_1s_addr.bit.b0
#define		psel1_p8_1s	p8_1s_addr.bit.b1
#define		psel2_p8_1s	p8_1s_addr.bit.b2

/*------------------------------------------------------
	Port P8_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p8_2s_addr;
#define		p8_2s	p8_2s_addr.byte

#define		psel0_p8_2s	p8_2s_addr.bit.b0
#define		psel1_p8_2s	p8_2s_addr.bit.b1
#define		psel2_p8_2s	p8_2s_addr.bit.b2

/*------------------------------------------------------
	Port P8_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p8_3s_addr;
#define		p8_3s	p8_3s_addr.byte

#define		psel0_p8_3s	p8_3s_addr.bit.b0
#define		psel1_p8_3s	p8_3s_addr.bit.b1
#define		psel2_p8_3s	p8_3s_addr.bit.b2

/*------------------------------------------------------
	Port P9_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p9_3s_addr;
#define		p9_3s	p9_3s_addr.byte

#define		psel0_p9_3s	p9_3s_addr.bit.b0
#define		psel1_p9_3s	p9_3s_addr.bit.b1
#define		psel2_p9_3s	p9_3s_addr.bit.b2
#define		asel_p9_3s	p9_3s_addr.bit.b7

/*------------------------------------------------------
	Port P8_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p8_4s_addr;
#define		p8_4s	p8_4s_addr.byte

#define		psel0_p8_4s	p8_4s_addr.bit.b0
#define		psel1_p8_4s	p8_4s_addr.bit.b1
#define		psel2_p8_4s	p8_4s_addr.bit.b2

/*------------------------------------------------------
	Port P9_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p9_4s_addr;
#define		p9_4s	p9_4s_addr.byte

#define		psel0_p9_4s	p9_4s_addr.bit.b0
#define		psel1_p9_4s	p9_4s_addr.bit.b1
#define		psel2_p9_4s	p9_4s_addr.bit.b2
#define		asel_p9_4s	p9_4s_addr.bit.b7

/*------------------------------------------------------
	Port P9_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p9_5s_addr;
#define		p9_5s	p9_5s_addr.byte

#define		psel0_p9_5s	p9_5s_addr.bit.b0
#define		psel1_p9_5s	p9_5s_addr.bit.b1
#define		psel2_p9_5s	p9_5s_addr.bit.b2
#define		asel_p9_5s	p9_5s_addr.bit.b7

/*------------------------------------------------------
	Port P8_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p8_6s_addr;
#define		p8_6s	p8_6s_addr.byte

#define		psel0_p8_6s	p8_6s_addr.bit.b0
#define		psel1_p8_6s	p8_6s_addr.bit.b1
#define		psel2_p8_6s	p8_6s_addr.bit.b2

/*------------------------------------------------------
	Port P9_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p9_6s_addr;
#define		p9_6s	p9_6s_addr.byte

#define		psel0_p9_6s	p9_6s_addr.bit.b0
#define		psel1_p9_6s	p9_6s_addr.bit.b1
#define		psel2_p9_6s	p9_6s_addr.bit.b2
#define		asel_p9_6s	p9_6s_addr.bit.b7

/*------------------------------------------------------
	Port P8_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p8_7s_addr;
#define		p8_7s	p8_7s_addr.byte

#define		psel0_p8_7s	p8_7s_addr.bit.b0
#define		psel1_p8_7s	p8_7s_addr.bit.b1
#define		psel2_p8_7s	p8_7s_addr.bit.b2

/*------------------------------------------------------
	Port P9_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p9_7s_addr;
#define		p9_7s	p9_7s_addr.byte

#define		psel0_p9_7s	p9_7s_addr.bit.b0
#define		psel1_p9_7s	p9_7s_addr.bit.b1
#define		psel2_p9_7s	p9_7s_addr.bit.b2

/*------------------------------------------------------
	Port P10_0 Function Select Register
------------------------------------------------------*/
union byte_def	far	p10_0s_addr;
#define		p10_0s	p10_0s_addr.byte

#define		psel0_p10_0s	p10_0s_addr.bit.b0
#define		psel1_p10_0s	p10_0s_addr.bit.b1
#define		psel2_p10_0s	p10_0s_addr.bit.b2
#define		asel_p10_0s	p10_0s_addr.bit.b7

/*------------------------------------------------------
	Port P10_1 Function Select Register
------------------------------------------------------*/
union byte_def	far	p10_1s_addr;
#define		p10_1s	p10_1s_addr.byte

#define		psel0_p10_1s	p10_1s_addr.bit.b0
#define		psel1_p10_1s	p10_1s_addr.bit.b1
#define		psel2_p10_1s	p10_1s_addr.bit.b2
#define		asel_p10_1s	p10_1s_addr.bit.b7

/*------------------------------------------------------
	Port P10_2 Function Select Register
------------------------------------------------------*/
union byte_def	far	p10_2s_addr;
#define		p10_2s	p10_2s_addr.byte

#define		psel0_p10_2s	p10_2s_addr.bit.b0
#define		psel1_p10_2s	p10_2s_addr.bit.b1
#define		psel2_p10_2s	p10_2s_addr.bit.b2
#define		asel_p10_2s	p10_2s_addr.bit.b7

/*------------------------------------------------------
	Port P10_3 Function Select Register
------------------------------------------------------*/
union byte_def	far	p10_3s_addr;
#define		p10_3s	p10_3s_addr.byte

#define		psel0_p10_3s	p10_3s_addr.bit.b0
#define		psel1_p10_3s	p10_3s_addr.bit.b1
#define		psel2_p10_3s	p10_3s_addr.bit.b2
#define		asel_p10_3s	p10_3s_addr.bit.b7

/*------------------------------------------------------
	Port P10_4 Function Select Register
------------------------------------------------------*/
union byte_def	far	p10_4s_addr;
#define		p10_4s	p10_4s_addr.byte

#define		psel0_p10_4s	p10_4s_addr.bit.b0
#define		psel1_p10_4s	p10_4s_addr.bit.b1
#define		psel2_p10_4s	p10_4s_addr.bit.b2
#define		asel_p10_4s	p10_4s_addr.bit.b7

/*------------------------------------------------------
	Port P10_5 Function Select Register
------------------------------------------------------*/
union byte_def	far	p10_5s_addr;
#define		p10_5s	p10_5s_addr.byte

#define		psel0_p10_5s	p10_5s_addr.bit.b0
#define		psel1_p10_5s	p10_5s_addr.bit.b1
#define		psel2_p10_5s	p10_5s_addr.bit.b2
#define		asel_p10_5s	p10_5s_addr.bit.b7

/*------------------------------------------------------
	Port P10_6 Function Select Register
------------------------------------------------------*/
union byte_def	far	p10_6s_addr;
#define		p10_6s	p10_6s_addr.byte

#define		psel0_p10_6s	p10_6s_addr.bit.b0
#define		psel1_p10_6s	p10_6s_addr.bit.b1
#define		psel2_p10_6s	p10_6s_addr.bit.b2
#define		asel_p10_6s	p10_6s_addr.bit.b7

/*------------------------------------------------------
	Port P10_7 Function Select Register
------------------------------------------------------*/
union byte_def	far	p10_7s_addr;
#define		p10_7s	p10_7s_addr.byte

#define		psel0_p10_7s	p10_7s_addr.bit.b0
#define		psel1_p10_7s	p10_7s_addr.bit.b1
#define		psel2_p10_7s	p10_7s_addr.bit.b2
#define		asel_p10_7s	p10_7s_addr.bit.b7

/*------------------------------------------------------
	Watchdog Timer Register
------------------------------------------------------*/
union byte_def	far	wdts_addr;
#define		wdts	wdts_addr.byte

/*------------------------------------------------------
	Watchdog Timer Control Register
------------------------------------------------------*/
union byte_def	far	wdc_addr;
#define		wdc	wdc_addr.byte

#define		wdc7	wdc_addr.bit.b7

/*------------------------------------------------------
	Protect Register 2
------------------------------------------------------*/
union byte_def	far	prcr2_addr;
#define		prcr2	prcr2_addr.byte

#define		prc27	prcr2_addr.bit.b7

/*------------------------------------------------------
	Interrupt cause select Register 1
------------------------------------------------------*/
union byte_def	far	ifsr1_addr;
#define		ifsr1	ifsr1_addr.byte

#define		ifsr16	ifsr1_addr.bit.b6

/*------------------------------------------------------
	Interrupt cause select Register 0
------------------------------------------------------*/
union byte_def	far	ifsr0_addr;
#define		ifsr0	ifsr0_addr.byte

#define		ifsr00	ifsr0_addr.bit.b0
#define		ifsr01	ifsr0_addr.bit.b1
#define		ifsr02	ifsr0_addr.bit.b2
#define		ifsr03	ifsr0_addr.bit.b3
#define		ifsr04	ifsr0_addr.bit.b4
#define		ifsr05	ifsr0_addr.bit.b5
#define		ifsr06	ifsr0_addr.bit.b6
#define		ifsr07	ifsr0_addr.bit.b7

/*------------------------------------------------------
	dma0 request cause select Register	2
------------------------------------------------------*/
union byte_def	far	dm0sl2_addr;
#define		dm0sl2	dm0sl2_addr.byte

#define		dsel20_dm0sl2	dm0sl2_addr.bit.b0
#define		dsel21_dm0sl2	dm0sl2_addr.bit.b1
#define		dsel22_dm0sl2	dm0sl2_addr.bit.b2
#define		dsel23_dm0sl2	dm0sl2_addr.bit.b3
#define		dsel24_dm0sl2	dm0sl2_addr.bit.b4
#define		dsr_dm0sl2		dm0sl2_addr.bit.b5

/*------------------------------------------------------
	dma1 request cause select Register	2
------------------------------------------------------*/
union byte_def	far	dm1sl2_addr;
#define		dm1sl2	dm1sl2_addr.byte

#define		dsel20_dm1sl2	dm1sl2_addr.bit.b0
#define		dsel21_dm1sl2	dm1sl2_addr.bit.b1
#define		dsel22_dm1sl2	dm1sl2_addr.bit.b2
#define		dsel23_dm1sl2	dm1sl2_addr.bit.b3
#define		dsel24_dm1sl2	dm1sl2_addr.bit.b4
#define		dsr_dm1sl2		dm1sl2_addr.bit.b5

/*------------------------------------------------------
	dma2 request cause select Register	2
------------------------------------------------------*/
union byte_def	far	dm2sl2_addr;
#define		dm2sl2	dm2sl2_addr.byte

#define		dsel20_dm2sl2	dm2sl2_addr.bit.b0
#define		dsel21_dm2sl2	dm2sl2_addr.bit.b1
#define		dsel22_dm2sl2	dm2sl2_addr.bit.b2
#define		dsel23_dm2sl2	dm2sl2_addr.bit.b3
#define		dsel24_dm2sl2	dm2sl2_addr.bit.b4
#define		dsr_dm2sl2		dm2sl2_addr.bit.b5

/*------------------------------------------------------
	dma3 request cause select Register	2
------------------------------------------------------*/
union byte_def	far	dm3sl2_addr;
#define		dm3sl2	dm3sl2_addr.byte

#define		dsel20_dm3sl2	dm3sl2_addr.bit.b0
#define		dsel21_dm3sl2	dm3sl2_addr.bit.b1
#define		dsel22_dm3sl2	dm3sl2_addr.bit.b2
#define		dsel23_dm3sl2	dm3sl2_addr.bit.b3
#define		dsel24_dm3sl2	dm3sl2_addr.bit.b4
#define		dsr_dm3sl2		dm3sl2_addr.bit.b5

/*------------------------------------------------------
	dma0 request cause select Register
------------------------------------------------------*/
union byte_def	far	dm0sl_addr;
#define		dm0sl	dm0sl_addr.byte

#define		dsel0_dm0sl	dm0sl_addr.bit.b0
#define		dsel1_dm0sl	dm0sl_addr.bit.b1
#define		dsel2_dm0sl	dm0sl_addr.bit.b2
#define		dsel3_dm0sl	dm0sl_addr.bit.b3
#define		dsel4_dm0sl	dm0sl_addr.bit.b4

/*------------------------------------------------------
	dma1 request cause select Register
------------------------------------------------------*/
union byte_def	far	dm1sl_addr;
#define		dm1sl	dm1sl_addr.byte

#define		dsel0_dm1sl	dm1sl_addr.bit.b0
#define		dsel1_dm1sl	dm1sl_addr.bit.b1
#define		dsel2_dm1sl	dm1sl_addr.bit.b2
#define		dsel3_dm1sl	dm1sl_addr.bit.b3
#define		dsel4_dm1sl	dm1sl_addr.bit.b4

/*------------------------------------------------------
	dma2 request cause select Register
------------------------------------------------------*/
union byte_def	far	dm2sl_addr;
#define		dm2sl	dm2sl_addr.byte

#define		dsel0_dm2sl	dm2sl_addr.bit.b0
#define		dsel1_dm2sl	dm2sl_addr.bit.b1
#define		dsel2_dm2sl	dm2sl_addr.bit.b2
#define		dsel3_dm2sl	dm2sl_addr.bit.b3
#define		dsel4_dm2sl	dm2sl_addr.bit.b4

/*------------------------------------------------------
	dma3 request cause select Register
------------------------------------------------------*/
union byte_def	far	dm3sl_addr;
#define		dm3sl	dm3sl_addr.byte

#define		dsel0_dm3sl	dm3sl_addr.bit.b0
#define		dsel1_dm3sl	dm3sl_addr.bit.b1
#define		dsel2_dm3sl	dm3sl_addr.bit.b2
#define		dsel3_dm3sl	dm3sl_addr.bit.b3
#define		dsel4_dm3sl	dm3sl_addr.bit.b4

/*------------------------------------------------------
	Exit Priority Register 2
------------------------------------------------------*/
union byte_def	far	ripl2_addr;
#define		ripl2	ripl2_addr.byte

#define		rlvl0_ripl2	ripl2_addr.bit.b0
#define		rlvl1_ripl2	ripl2_addr.bit.b1
#define		rlvl2_ripl2	ripl2_addr.bit.b2
#define		fsit_ripl2	ripl2_addr.bit.b3
#define		dmaii_ripl2	ripl2_addr.bit.b5

/*------------------------------------------------------
	Exit Priority Register 1
------------------------------------------------------*/
union byte_def	far	ripl1_addr;
#define		ripl1	ripl1_addr.byte

#define		rlvl0_ripl1	ripl1_addr.bit.b0
#define		rlvl1_ripl1	ripl1_addr.bit.b1
#define		rlvl2_ripl1	ripl1_addr.bit.b2
#define		fsit_ripl1	ripl1_addr.bit.b3
#define		dmaii_ripl1	ripl1_addr.bit.b5

