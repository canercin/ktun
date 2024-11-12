from flask import Flask, render_template, send_file, redirect, url_for
import random
import pandas as pd
import matplotlib.pyplot as plt
import io

app = Flask(__name__)

def create_random_plot():
    xlist = [random.randrange(0, 1000) for _ in range(1000)]
    ylist = [random.randrange(0, 1000) for _ in range(1000)]
    
    df = pd.DataFrame({'x': xlist, 'y': ylist})
    df.to_excel('hw6.xlsx', index=False)
    
    plt.figure(figsize=(10, 10))
    plt.title('Koordinat Noktaları Izgaraya Bölünmüş')
    plt.xlabel('X Koordinatları')
    plt.ylabel('Y Koordinatları')
    gridsize = 200
    colors = ('r', 'g', 'b', 'c', 'm', 'y', 'k')
    
    for i in range(0, 1000, gridsize):
        for j in range(0, 1000, gridsize):
            in_grid = (df['x'] >= i) & (df['x'] < i + gridsize) & (df['y'] >= j) & (df['y'] < j + gridsize)
            plt.scatter(df['x'][in_grid], df['y'][in_grid], color=random.choice(colors), label=f'Grid ({i},{j})')

    for i in range(0, 1000, gridsize):
        plt.axvline(x=i, color='k', linestyle='--', linewidth=0.5)  
        plt.axhline(y=i, color='k', linestyle='--', linewidth=0.5)  
    
    plt.axvline(x=1000, color='k', linestyle='--', linewidth=0.5)
    plt.axhline(y=1000, color='k', linestyle='--', linewidth=0.5)
    
    img = io.BytesIO()
    plt.savefig(img, format='jpeg')
    img.seek(0)
    
    return img

@app.route('/')
def index():
    return render_template('index.html')

@app.route('/plot')
def plot():
    img = create_random_plot()
    return send_file(img, mimetype='image/jpeg')

@app.route('/refresh')
def refresh():
    return redirect(url_for('plot'))

if __name__ == '__main__':
    app.run(debug=True)
