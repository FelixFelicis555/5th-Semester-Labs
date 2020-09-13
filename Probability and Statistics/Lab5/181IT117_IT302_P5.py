import xlrd 

# Reading the Excel file as input
loc=("D:/Academics/5th Sem/Prob and Stats/Lab Programs/Lab5/Test-Cases-IT302-Lab-Program-5.xlsx")
wb = xlrd.open_workbook(loc) 
sheet = wb.sheet_by_index(0) 

c=[]
for i in range(0,sheet.nrows):
	for j in range(0,sheet.ncols):
		if sheet.cell_value(i,j)=="f(x,y)":
			c.append([i,j])
			break
r=[]
r2=[]
check=0
for c1 in c:
	check=0
	for i in range(c1[1]+2,sheet.ncols):
		
		if sheet.cell(c1[0]+1,i).value == xlrd.empty_cell.value:
			r.append([c1[1]+2,i])
			check=1
			break
	if check==0:
		r.append([c1[1]+2,i+1])
for c1 in c:
	check=0
	for i in range(c1[0]+2,sheet.nrows):
		if sheet.cell(i,c1[1]+1).value == xlrd.empty_cell.value:
			r2.append([c1[0]+2,i])
			check=1
			break
	if check==0:
		r2.append([c1[0]+2,i+1])


l=len(r)
for g in range(0,l):

	f={}
	outp=open(f"181IT117_IT302_P5_Output_TC{g+1}.txt","a")
	for i in range(r[g][0],r[g][1]):
		for j in range(r2[g][0],r2[g][1]):
			f[str(int(sheet.cell_value(r2[g][0]-1, i)))+","+str(int(sheet.cell_value(j, r[g][0]-1)))]=sheet.cell_value(j, i)

	print(f"f(x,y){g}: ",f)
	for i in f:
		if f[i]>1:
			outp.write(f"\nf({i}): "+str(f[i])+" is greater than 1 and is invalid")
			break
		outp.write(f"\nf({i}): "+str(f[i]))
	e=0
	for i in f:
		xy=i.split(",")
		x=int(xy[0])
		y=int(xy[1])
		e+= 2*x*y*f[i]
	print(f"Expected value of g (X, Y) = 2XY for f{g}: "+str(e))
	outp.write(f"\nExpected value of g (X, Y) = 2XY for f{g}: "+str(e))
	Mx=0
	for i in f:
		xy=i.split(",")
		x=int(xy[0])
		y=int(xy[1])
		Mx+=x*f[i]
	print("μX : "+str(Mx))
	outp.write(f"\n uX : "+str(Mx))

	My=0
	for i in f:
		xy=i.split(",")
		x=int(xy[0])
		y=int(xy[1])
		My+=y*f[i]
	print("μY : "+str(My))
	outp.write(f"\n uY : "+str(My))

	outp.close()


