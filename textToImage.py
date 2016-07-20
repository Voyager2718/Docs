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
        print('Enter background rgb or color name:')
        bgColor = input().replace('(', '').replace(')', '')
        try:
            bgColor = tuple((int(x.strip()) for x in bgColor.split(',')))
        except ValueError:
            try:
                bgColor = bgColor.replace(' ', '').lower()
                bgColor = {
                    'black': (0, 0, 0),
                    'white': (255, 255, 255),
                    'gray': (128, 128, 128),
                    'red': (255, 0, 0),
                    'lime': (0, 255, 0),
                    'green': (0, 255, 0), 
                    'blue': (0, 0, 255),
                    'yellow': (255, 255, 0),
                    'orange': (255, 128, 0),
                    'cray': (0, 255, 255)
                }[bgColor]
            except KeyError:
                print('Fatal Error: Enter a RGB color like (128, 128, 128) or a color name within white, black, gray, red, lime, green, blue, yellow, orange, cray.')
                print('-'  * 25)
                continue
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
        print('Enter font rgb or color name:')
        fontColor = input().replace('(', '').replace(')', '')
        try:
            fontColor = tuple((int(x.strip()) for x in fontColor.split(',')))
        except ValueError:
            try:
                fontColor = fontColor.replace(' ', '').lower()
                fontColor = {
                    'black': (0, 0, 0),
                    'white': (255, 255, 255),
                    'gray': (128, 128, 128),
                    'red': (255, 0, 0),
                    'lime': (0, 255, 0),
                    'green': (0, 255, 0), 
                    'blue': (0, 0, 255),
                    'yellow': (255, 255, 0),
                    'orange': (255, 128, 0),
                    'cray': (0, 255, 255)
                }[fontColor]
            except KeyError:
                print('Fatal Error: Enter a RGB color like (128, 128, 128) or a color name within white, black, gray, red, lime, green, blue, yellow, orange, cray.')
                print('-'  * 25)
                continue
        print('Enter a path to save the image:')
        path = input()
        valid = True
    draw(text, (int(sizeX), int(sizeY)), bgColor, font, fontSize, fontColor, path)
    print('Success!\nSaved to', path)

if __name__ == '__main__':
    main()
