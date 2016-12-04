// RGBpixmap.cpp, 10/14/99, by F.S.Hill,Jr. - for ECE660
// fixed 11/7/98 to prevent openGL from trying to align pixels to 4 byte boundaries
// in memory, which it does by default.

#include "RGBpixmap.hpp"
fstream inf;  // global in this file for convenience
fstream outf; // ditto
//<<<<<<<<<<<<<<<<<<<<< putShort >>>>>>>>>>>>>>>>>>>>
void putShort(ushort i)
{ // write short in little-endian form
	outf.put((char)(i & 0xff));
	outf.put((char)((i >> 8) & 0xff));	
}
//<<<<<<<<<<<<<<<<<<<<< putLong >>>>>>>>>>>>>>>>>>>>
void putLong(ulong i)
{ // write long in little-endian form
	outf.put((char)(i & 0xff));
	outf.put((char)((i >> 8) & 0xff));	
	outf.put((char)((i >> 16) & 0xff));	
	outf.put((char)((i >> 24) & 0xff));	
}
//<<<<<<<<<<<<<<<<<<<<< getShort >>>>>>>>>>>>>>>>>>>>
ushort getShort()
{// read a short in little-endian form
	char ic;
	ushort ip;
	inf.get(ic); ip = ic;  //first byte is little one 
	inf.get(ic);  ip |= ((ushort)ic << 8); // or in high order byte
	return ip;
}
//<<<<<<<<<<<<<<<<<<<< getLong >>>>>>>>>>>>>>>>>>>
ulong getLong()
{  // get little-endian 4-byte value from file, compose along portably
	ulong ip = 0;
	char ic = 0;
	unsigned char uc = ic;
	inf.get(ic); uc = ic; ip = uc;
	inf.get(ic); uc = ic; ip |=((ulong)uc << 8);
	inf.get(ic); uc = ic; ip |=((ulong)uc << 16);
	inf.get(ic); uc = ic; ip |=((ulong)uc << 24);
	return ip;
}
//<<<<<<<<<<<<<<<<<< RGBPixmap:: readBmpFile>>>>>>>>>>>>>
int RGBpixmap:: readBMPFile(string fname) 
{  
	// Read into memory an mRGB image from an uncompressed BMP file.
	// return 0 on failure, 1 on success
	inf.open(fname.c_str(), ios::in|ios::binary); //must read raw binary char's.
	
	if(!inf)
	{ 
		cout << " can't open file: " << fname << endl; return 0;
	}

	int k, row, col, numPadBytes, nBytesInRow;
	// read header information
	char ch1, ch2;
	inf.get(ch1); 
	inf.get(ch2);		// type is always 'BM'

	//cout << "file type = " << ch1 << ch2 << endl;
	ulong fileSize =	getLong();
	ushort reserved1 =  getShort();     // always 0
	ushort reserved2 = 	getShort();     // always 0 
	ulong offBits =		getLong();	    // offset to image - unreliable
	ulong headerSize =  getLong();      // always 40
	ulong numCols =		getLong();	    // number of columns in image
	ulong numRows = 	getLong();	    // number of rows in image
	ushort planes=    	getShort();     // always 1 
	ushort bitsPerPix = getShort();     // 8 or 24;only 24 bit case done 
	ulong compression = getLong();		// must be 0 for umcompressed 
	ulong imageSize = 	getLong();      // total bytes in image 
	ulong xPels =    	getLong();      // always 0 
	ulong yPels =    	getLong();      // always 0 
	ulong numLUTentries = getLong();	// 256 for 8 bit, otherwise 0 
	ulong impColors = 	getLong();      // always 0 

	if(bitsPerPix != 24) 
	{
		cout << "not a 24 bit/pixelimage!\n"; inf.close(); return 0;
	}; // error!

	// in BMP file, pad bytes inserted at end of each row so total number is a mult. of 4
	nBytesInRow = ((3 * numCols + 3)/4) * 4; // round up 3*numCols to next mult. of 4
	numPadBytes = nBytesInRow - 3 * numCols; // need this many
	
	nRows = numRows; // set class's data members
	nCols = numCols;
	cout.flush();
	pixel = new mRGB[nRows * nCols]; //space for array in memory
	
	if(!pixel) return 0; // out of memory!
	long count = 0;
	char dum,r,g,b;
	
	for(row = 0; row < nRows; row++) // read pixel values
	{
		for(col = 0; col < nCols; col++)
		{
			inf.get(b); inf.get(g); inf.get(r); // funny color order in BMP file
			pixel[count].r = r; pixel[count].g = g; pixel[count++].b = b;
		}
      for(k = 0; k < numPadBytes ; k++) //skip over padding bytes at row's end
			inf >> dum;
	}
	inf.close();
	return 1; // success
}

void RGBpixmap :: setTexture(unsigned int textureName)
{
	glBindTexture(GL_TEXTURE_2D,textureName);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB,nCols,nRows,0, GL_RGB, 	GL_UNSIGNED_BYTE, pixel);
}
