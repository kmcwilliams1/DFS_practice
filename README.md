#  Project : SimCity

----------------------------------------------------------------------------------
## File Format

Format of output:
data.dat ← Name of file

0/20 ← Current Step / Total Steps

3 ← Step frequency of output for current state of region

[ ] ← Region or map

Key:

·  R represents a residential zone
 
·  I represents an industrial zone

·  C represents a commercial zone

·  - represents a road

·  T represents a powerline

·  # represents a powerline over a road

·  P represents a power plant

 ----------------------------------------------------------------------------------
## Rules

·  The simulation should halt when there is no change between two, consecutive time steps or when the time limit has been reached, whichever comes first

·  The current time step, number of available workers, and number of available goods should be output for each timestep except time step 0

·  The state of the region should be output at the frequency denoted by the refresh rate in the configuration file

·  The region is considered to be flat, and thus the edges do not wrap around to connect to each other

·  Two cells are considered adjacent if they share an edge or corner (i.e. a cell may be adjacent to a maximum of eight other cells, and a minimum of three other cells)

·  Each of the zoned cells will change their state according to the provided rules

 ----------------------------------------------------------------------------------


#### In the event of a decision needing to be made over two zoned cells that could grow and use available resources, the following rules must be used in order:

Commercial zoned cells are prioritized over industrial zoned cells

The growth of larger population zoned cells is prioritized over smaller population zoned cells (i.e. a 1 population cell will always grow before a 0 population cell)

The growth of zoned cells with greater total adjacent populations is prioritized over zoned cells with smaller total adjacent populations

The growth of zoned cells with smaller Y coordinates is prioritized over zoned cells with greater Y coordinates, assuming the top left cell is 0,0

The growth of zoned cells with smaller X coordinates is prioritized over zoned cells with greater X coordinates, assuming the top left cell is 0,0


----------------------------------------------------------------------------------
Functions of Each File
----------------------------------------------------------------------------------
### Main
  Allow the user to input the file containing the simulation configuration

  Read in and store the simulation configuration information

  Read in and store the initial region layout If a cell has a population of 0 and is adjacent to at least one cell with

  Output the initial region state


 Simulate the development of the city over time

  Output the final region state

  Output the total, regional population for residential zones, industrial zones, and commercial zones

 Output the final regional pollution state

 Output the total pollution in the region

Prompt the user for the coordinates of some rectangular area of the region to analyze more closely

 Output the total population for residential zones, industrial zones, and commercial zones within the area specified by the user

  Output the total pollution within the area specified by the user
 

----------------------------------------------------------------------------------

### Residential
If a cell has a population of 0 and is adjacent to a powerline in the current time step, that cell’s population will increase by 1 in the next time step

If a cell has a population of 0 and is adjacent to at least one cell with a population of at least 1, that cell’s population will increase by 1 in the next time step

If a cell has a population of 1 and is adjacent to at least two cells with a population of at least 1, that cell’s population will increase by 1 in the next time step

If a cell has a population of 2 and is adjacent to at least four cells with a population of at least 2, that cell’s population will increase by 1 in the next time step

If a cell has a population of 3 and is adjacent to at least six cells with a population of at least 3, that cell’s population will increase by 1 in the next time step

If a cell has a population of 4 and is adjacent to at least eight cells with a population of at least 4, that cell’s population will increase by 1 in the next time step

The residential population provides workers to the industrial and commercial zones, but each worker can only have one job

----------------------------------------------------------------------------------
### Industrial

If a cell has a population of 0, is adjacent to a powerline in the current time step, and there are at least 2 available workers, that cell’s population will increase by 1 in the next time step and the available workers are assigned to that job

If a cell has a population of 0, is adjacent to at least one cell with a population of at least 1, and there are at least 2 available workers, that cell’s population will increase by 1 in the next time step and the available workers are assigned to that job

If a cell has a population of 1, is adjacent to at least two cells with a population of at least 1, and there are at least 2 available workers, that cell’s population will increase by 1 in the next time step and the available workers are assigned to that job

If a cell has a population of 2, is adjacent to at least four cells with a population of at least 2, and there are at least 2 available workers, that cell’s population will increase by 1 in the next time step and the available workers are assigned to that job

A cell produces pollution equal to its population, and pollution spreads to all adjacent cells at a rate of one less unit of pollution per cell away from the source

The industrial population provides goods to the commercial zones, at a rate of one good per population, but each good can only be sold at one commercial cell

  ----------------------------------------------------------------------------------
### Commercial
If a cell has a population of 0, is adjacent to a powerline in the current time step, there is at least 1 available worker, and there is at least one available good, that cell’s population will increase by 1 in the next time step and the available worker and available good are assigned to that job

If a cell has a population of 0, is adjacent to at least one cell with a population of at least 1, there is at least 1 available worker, and there is at least one available good, that cell’s population will increase by 1 in the next time step and the available worker and available good are assigned to that job

If a cell has a population of 1, is adjacent to at least two cells with a population of at least 1, there is at least 1 available worker, and there is at least one available good, that cell’s population will increase by 1 in the next time step and the available worker and available good are assigned to that job

  ----------------------------------------------------------------------------------

 

