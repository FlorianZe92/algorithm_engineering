import matplotlib.pyplot as plt
import pandas as pd



#read_file = pd.read_csv ('x_value.txt', sep = '\t')


#with open('x_value.txt', 'w') as f:
#    for line in read_file['x']:
#        f.write(str(line)+' ')

#with open('y_value.txt', 'w') as f:
#    for line in read_file['y']:
#        f.write(str(line)+' ')

data_x = pd.read_csv('x.csv', header = None, sep = '\t')
data_y = pd.read_csv('y.csv', header = None, sep = '\t')

plt.plot(data_x,data_y,'bs')
plt.xlim((-5, 105))
plt.ylim((-5, 105))
plt.tight_layout()

plt.show()
