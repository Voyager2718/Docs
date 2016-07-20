from PIL import Image, ImageFont, ImageDraw

def draw(text, size, bgColor, font, fontSize, fontColor, path):
    img = Image.new('RGBA', size, bgColor)
    font = ImageFont.truetype(font, fontSize)
    draw = ImageDraw.Draw(img)
    draw.text((10, 10), text, fontColor, font = font)
    img.save(path)

def main():
    valid = False
    while(not valid):
        print('Enter your text:')
        text = input()
        print('Enter your image sizeX:')
        sizeX = input()
        try:
            sizeX = int(sizeX)
        except ValueError:
            print('Fatal Error: Enter a integer.')
            print('-'  * 25)
            continue
        print('Enter your image sizeY:')
        sizeY = input()
        try:
            sizeY = int(sizeY)
        except ValueError:
            print('Fatal Error: Enter a integer.')
            print('-'  * 25)
            continue
        bgColor = (255, 255, 255)
        print('Enter a font file:')
        font = input()
        try:
            open(font, 'r')
        except FileNotFoundError:
            print('Fatal Error: Unable to open file')
            print('-'  * 25)
            continue
        print('Enter the font size:')
        fontSize = input()
        try:
            fontSize = int(fontSize)
        except ValueError:
            print('Fatal Error: Enter a integer.')
            print('-'  * 25)
            continue
        print('Enter a path to save the image:')
        fontColor = (0, 0, 0) 
        path = input()
        valid = True
    draw(text, (int(sizeX), int(sizeY)), bgColor, font, fontSize, fontColor, path)
    print('Success!\nSaved to', path)

if __name__ == '__main__':
    main()
