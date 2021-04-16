/*              
Sources: 
    Mailbox Peripheral  : https://jsandler18.github.io/extra/mailbox.html
    Properaty Mailbox   : https://jsandler18.github.io/extra/prop-channel.html

            Getting a FrameBuffer
1.Get screen size, virtual screen size and depth
    *The Depth of a framebuffer is the number of bits in every pixel. 
    *For this tutorial, we will be exclusively using a depth of 24, 
    *meaning that each of the red, green and blue values will have 8 bits, or 1 byte to them.
1.b.Tag ids:
    screen size:         0x00048003
    virtual screen size: 0x00048004
    depth:               0x00048005
2.Get screen size by passing 4 byte wide width and 4 byte wide height, no result
3.Set depth by passing 4 byte depth value, no result
4.Example screen size 640x480 with depth to 24:
    80,                             // The whole buffer is 80 bytes
    0,                              // This is a request, so the request/response code is 0
    0x00048003, 8, 0, 640, 480,     // This tag sets the screen size to 640x480
    0x00048004, 8, 0, 640, 480,     // This tag sets the virtual screen size to 640x480
    0x00048005, 4, 0, 24,           // This tag sets the depth to 24 bits
    0,                              // This is the end tag
    0, 0, 0                         // This pads the message to by 16 byte aligned
5.Sent this buffer through mailbox. 16 byte aligned so high 28 bits contain address. 
    bitwise or 8 with this address, setting hte low 4 bits to the channel number
6.Send through mailbox periheral, which facilitates communication bewteen CPU and VideoCore
    1.Starts 0xb880 and has three relevent regs
    2.Read register is at offset 0x00
    3.Status register at offset 0x18. bit 30 indicates read is empty and 31 write is full
    4.write register is at offset 0x20. Similar to read 
    5.Mailbox peripheral layout:
            0       4       8      12      16      20      24      28      32
            +-------+-------------------------------------------------------+
        0x00   |rd chn |                     read data                         |
            +-------+-------------------------------------------------------+
        0x04   |                             Unused                            |
        ...    \\                                                             \\
        0x14   |                             Unused                            |
            +-----------------------------------------------------------+-+-+
        0x18   |      status reserved                                      |E|F|
            +-----------------------------------------------------------+-+-+
        0x1C   |                             Unused                            |
            +-----------------------------------------------------------+-+-+
        0x20   |wt chn |                    write data                         |
            +-----------------------------------------------------------+-+-+
7.Verify it worked by checking req/res code of buffer. 0=failed, 0x80000001=error, 0x80000000=success
8.Request Frame buffer from tag id 0x00040001
    1.4 byte param, the requested aligment of the framebuffer and returns two 4 byte values
    2.Value buffer has size 8 asking for 16 byte aligned
    3.ex:
        32,                         // The whole buffer is 32 bytes
        0,                          // This is a request, so the request/response code is 0
        0x00040001, 8, 0, 16, 0,    // This tag requests a 16 byte aligned framebuffer
        0                           // This is the end tag

*/