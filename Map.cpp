#include"Map.h"

Map::Map(string srcFile)
{
	if(!(loadFile(srcFile)))
	{
		cout<<"File cannot open"<<endl;
	}
}

//Read in the map
bool Map::loadFile(string src)
{

        string temp;
        int i = 0;
        int j = 0;

        //if(read_file==0)
        ifstream infile;
        //Open the designated file
        //infile.open("practice.txt");
	infile.open(src);
	
	
         //If file was open sucessfully then eneter
        if(infile)
        {

                //If end of file is not triggered then enter the loop
                while(getline(infile,temp))
                {
                        for(unsigned int k = 0;k<temp.size();++k)
                        {

                                if(j == MAPSIZE)
                                {
                                        ++i;
                                        j=0;
                                }

				switch(temp[k])
				{               
					case 'W':
						tileArray[i][j].type = new Water;//Color num 4
						break;
					case 'M':
						tileArray[i][j].type = new Wall;//Color num 7
						break;
					case 'S':
						tileArray[i][j].type = new Swamp; //Color num 5
						break;
					case 'G':
						tileArray[i][j].type = new Meadow; //Color num 2
						break;
				}

                                ++j;

				//How should we go about occupants?

                        }




                }
                infile.close();

        }
	/*
	attron(COLOR_PAIR(5));
	mvwprintw(win,5 ,5," ");
	wrefresh(win);
	*/
}

bool Map::saveFile(string dest)
{
	//Variable: Outfile
	ofstream outfile;
	//Open the data.txt files
        outfile.open("Custom.txt");
	//Clear what was in function
        outfile.clear();
	//Close the file
	outfile.close();
	//Reopen another file
        outfile.open("Custom.txt", ios::app);


	//Loop through list.
	
	for(int i=0;i<MAPSIZE;++i)
	{
		for(int j = 0; j<MAPSIZE; ++j)
		{
			if(tileArray[i][j].type == Meadow)
				outfile<<"G";
			else if(tileArray[i][j].type == Water)
				outfile<<"W";
			else if(tileArray[i][j].type == Wall)
				outfile<<"M";
			else if(tileArray[i][j].type == Swamp)
				outfile<<"S";

		}
		outfile<<endl;
	}
	//Close the file
        outfile.close();

	return true;
}

//Return what type of tile it is
TileType * Map::tileTypeAt(int row, int col)
{
	return tileArray[row][col].type;
}
//Return what  occupies the tile
TileOccupant * Map::occupantAt(int row, int col)
{
	return tileArray[row][col].occupant;
}
//Reveal the tile(Discovered)
void Map::tile_revealed(int row, int col)
{
	tileArray[row][col].revealed = true;
}

//Have we been at tile before
bool Map::isTileDiscovered(int row, int col)
{
	if(tileArray[row][col].revealed)
		return true;

	return false;
}

//Display what is discovered
void Map::displayMap(WINDOW * win)
{
	char MarkerDisplay;
	//Print the Grovnicks that are used
	for(int i = MinY; i<MaxY; ++i)
	{
		for(int j = MinX; j<MaxX; ++j)
		{
			if(tileArray[i][j].revealed)
			{
				if(tileArray[i][j].occupant)
					MarkerDisplay = tileArray[i][j].occupant->marker();
				else
					MarkerDisplay = " ";

				if(tileArray[i][j].occupant != NULL && tileArray[i][j].occupant == Diamond)
				{
					attron(COLOR_PAIR(1));
					mvwprintw(win,i -MinY ,j-MinX, MarkerDisplay);
				}
				else
				{
					attron(COLOR_PAIR(tileArray[i][j].type->color()));
					mvwprintw(win,i -MinY ,j-MinX, MarkerDisplay);
				}
			}
		}
	}
}
