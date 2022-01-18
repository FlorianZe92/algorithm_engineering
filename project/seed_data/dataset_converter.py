import matplotlib.pyplot as plt
import pandas as pd


read_file = pd.read_csv('angled_blob.csv',header=None)

read_file[0].to_csv('x_Datasaurus', sep='\t', encoding='utf-8', header=False,index=False)
