/*                       Frame Buffering
*Raspi2 and up CPU commuicates with the GPU using the Properaty Channel
*Send property channel 32 bit message which is 16 byte aligned
*Request and response code. send must equal 0. Recieving 0x80000000 for success and 0x80000001 for failure
*End tage is 4 bytes of zeros
*Message must be padded some 16 byte align
*/


/*
                           Message Structure

       0       4       8      12      16      20      24      28      32
       +---------------------------------------------------------------+
0x00   |                         Buffer Size                           |
       +---------------------------------------------------------------+
0x04   |                   Request/Response Code                       |
       +---------------------------------------------------------------+
0x08   |                             Tags                              |
...    \\                                                             \\
0xXX   |                             Tags                              |
       +---------------------------------------------------------------+
0xXX+4 |                           End Tag (0)                         |
       +---------------------------------------------------------------+
0xXX+8 |                           Padding                             |
...    \\                                                             \\
0xXX+16|                           Padding                             |
       +---------------------------------------------------------------+

*/

/*                     Message Tags
*A tag is a command to get or set hardware
*Starts with 4 byte tag ID, structured 0x000xyzzz, x = which hardware device youre accessing, y=which type 
*   of command(0=get, 4=test, 8=set) and zzz identifies specific command
*Size fhould be be the max of the size of the parameters for the command and the size of the results
*When sending message, should be 0, when receiving, should be 0x80000000 + length of the result
*value buffer is where rseults are stored. buffer is an 8 bit (uint8_t) array
*pad to make 4 byte aligned
*/

/*
       0       4       8      12      16      20      24      28      32
       +---------------------------------------------------------------+
0x00   |                         Tag Identity                          |
       +---------------------------------------------------------------+
0x04   |                       Value Buffer Size                       |
       +---------------------------------------------------------------+
0x08   |                     Request/Response Code                     |
       +---------------------------------------------------------------+
0x0C   |                          Value Buffer                         |
...    \\                                                             \\
0xXX   | Value Buffer  |                    Padding                    |
       +---------------------------------------------------------------
*/