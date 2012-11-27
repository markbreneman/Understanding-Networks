import processing.data.*;

ArrayList entry; 
ArrayList entryrow;
ArrayList arduinoData;
Table data;

void setup() {
  //  size(800, 800);
  // load the data and automatically parse the csv
  data = new Table(this, "../test5_112612_0426PM.csv");//go one directory up and fetch the file.
  data.removeTitleRow();//remove Control ROW
  data.removeTitleRow();//remove Interval and Apt labesl

  //Create and Array list for all the entries
  entry = new ArrayList();
  // iterate through the data in the csv
  for (TableRow cols : data) {
    entryrow = new ArrayList();  
    entryrow.add(cols.getString(0));//Time Interval
    entryrow.add(cols.getFloat(1));//Apt 14n
    entryrow.add(cols.getFloat(2));//Apt 14o
    entryrow.add(cols.getFloat(3));//Apt 14q
    entryrow.add(cols.getFloat(4));//Apt 14p
    entryrow.add(cols.getFloat(5));//Apt 14r
    entryrow.add(cols.getFloat(6));//Apt 18A
    entryrow.add(cols.getFloat(7));//Apt 18E
    entryrow.add(cols.getFloat(8));//Apt 18I
    entryrow.add(cols.getFloat(9));//Outdoor Temp
    entryrow.add(cols.getFloat(10));//System Temp
    entry.add(entryrow);
  }

  //THIS ARRAY IS THE CONTAINS THE CONVERTED DATA- Meaning Logic is applied

  arduinoData = new ArrayList();
  float hotThreshold=75;
  float SDT=100;//System Difference Threshold. System minus Building Temp.
  
  for (TableRow cols : data) {
    entryrow = new ArrayList();
    //APT 14n 
    if (cols.getFloat(1)>hotThreshold) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    //APT 14o 
    if (cols.getFloat(2)>hotThreshold) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    //APT 14q 
    if (cols.getFloat(3)>hotThreshold) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    //APT 14p 
    if (cols.getFloat(4)>hotThreshold) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    //APT 14r 
    if (cols.getFloat(5)>hotThreshold) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    //APT 18a 
    if (cols.getFloat(6)>hotThreshold) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    //APT 18e 
    if (cols.getFloat(7)>hotThreshold) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    //APT 18i 
    if (cols.getFloat(8)>hotThreshold) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    //Delta Outside/System Temp 
    if (cols.getFloat(10)-cols.getFloat(9)>SDT) {
      entryrow.add(1);
    }
    else {
      entryrow.add(0);
    }

    arduinoData.add(entryrow);
  }
}
void draw() {
}

void keyPressed() {
  if (key =='i') {
    println(entry);
  }
  
  if (key =='l') {
    println(arduinoData);
  }
}

