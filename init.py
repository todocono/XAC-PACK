
# Part of of https://github.com/todocono/XAC-PACK

# Clients: Children's Hospital Eastern Ontario
# Organization: Tetra Society

# Released under RG-M Pacifist License, which is basically a MIT-modified license.
# (original MIT license is available on http://www.opensource.org/licenses/mit-license).
# The main amendment prevents the work under license or any other drived work from:
# war purposes, or purposes related to death penalty.

# Coded by Rodolfo Cossovich
# Latest update: 2023-10-12

import pygame, buttons

global menu, pressRight, pressLeft, pressUp, pressDown

class button:
    def __init__(self, position, size, clr=[100, 100, 100], cngclr=None, func=None, func_down=None, func_up=None, text='', font="Segoe Print", font_size=16, font_clr=[0, 0, 0], hover_state=False):
        self.clr    = clr
        self.size   = size
        self.func   = func
        self.func_down   = func_down
        self.func_up   = func_up
        self.surf   = pygame.Surface(size)
        self.rect   = self.surf.get_rect(center=position)
        self.hover_state = True  #Was it in hover state?

        if cngclr:
            self.cngclr = cngclr
        else:
            self.cngclr = clr

        #if len(clr) == 4:
            #self.surf.set_alpha(clr[3])


        self.font = pygame.font.SysFont(font, font_size)
        self.txt = text
        self.font_clr = font_clr
        self.txt_surf = self.font.render(self.txt, 1, self.font_clr)
        self.txt_rect = self.txt_surf.get_rect(center=[wh//2 for wh in self.size])

    def draw(self, screen):
        self.mouseover()

        self.surf.fill(self.curclr)
        self.surf.blit(self.txt_surf, self.txt_rect)
        screen.blit(self.surf, self.rect)

    def mouseover(self):
        self.curclr = self.clr
        pos = pygame.mouse.get_pos()

        if self.rect.collidepoint(pos):
            self.curclr = self.cngclr
            #I check if it was in hover situation

            if not self.hover_state:
              self.hover_state = True

              if self.func_down:
                self.func_down()
                #print(self.hover_state)

        else:
          if self.hover_state:
            self.hover_state = False
            if self.func_up:
              self.func_up()
              #print(self.hover_state)


    def call_back(self, *args):
        if self.func:
            return self.func(*args)

class text:
    def __init__(self, msg, position, clr=[100, 100, 100], font="Segoe Print", font_size=15, mid=False):
        self.position = position
        self.font = pygame.font.SysFont(font, font_size)
        self.txt_surf = self.font.render(msg, 1, clr)

        if len(clr) == 4:
            self.txt_surf.set_alpha(clr[3])

        if mid:
            self.position = self.txt_surf.get_rect(center=position)


    def draw(self, screen):
        screen.blit(self.txt_surf, self.position)




# call back functions
def fnBACK():
    global menu
    print('back')
    menu = 1
def fnSTART():
    print('MODE 1')
    global menu
    menu = 3
def fnCONFIG():
    print('MODE 2')
    global menu
    menu = 2

def fnDOWN():
    print('DOWN')
def fnLEFT():
    print('LEFT')
def fnRIGHT():
    print('RIGHT')
def fnUP():
    print('UP')




if __name__ == '__main__':
    pygame.init()
    screen_size = (300, 200)
    size        = 20
    clr         = [255, 0, 255]
    bg          = (120, 120, 0)
    font_size   = 30
    font        = pygame.font.Font(None, font_size)
    clock       = pygame.time.Clock()

    #screen    = pygame.display.set_mode(screen_size)
    screen = pygame.display.set_mode((0, 0), pygame.FULLSCREEN)
    w, h = pygame.display.get_surface().get_size()

    pygame.mouse.set_visible(False)
    pygame.event.set_grab(False)
    menu = 2 #1   #automatically set
    pressRight = False
    pressLeft = False
    pressDown = False
    pressUp = False

     #MENU BUTTONS
    buttonSTART = button(position=(w/8, h/2), size=(h, w/2), clr=(220, 220, 220), cngclr=(255, 0, 0), func=fnSTART, text='Mode 1', font_size = font_size)
    buttonCONFIG = button(position=(7*w/8, h/2), size=(h, w/2),  clr=(220, 220, 220), cngclr=(255, 0, 0), func=fnCONFIG, text='Mode 2', font_size = font_size)


    buttonBACK = button(position=(w/16, h/16), size=(w/8, h/8), clr=(100, 220, 100), cngclr=(255, 255, 0), func=fnBACK, text='Back', font_size = font_size // 2)


    buttonLEFT = button(position=(w/9, h/2), size=(w/3, h), clr=(220, 220, 220), cngclr=(255, 0, 0), func=fnLEFT, func_down=buttons.fnLEFT_down, func_up=buttons.fnLEFT_up, text='LEFT', font_size = font_size)
    buttonRIGHT = button((8*w/9, h/2), (w/3, h), (220, 220, 220), (255, 0, 0), fnRIGHT, buttons.fnRIGHT_down, buttons.fnRIGHT_up, 'RIGHT', font_size = font_size)
    buttonUP = button(position=(w/2, h/9), size=(w, h/3), clr=(220, 220, 220), cngclr=(255, 0, 0), func=fnUP, func_down=buttons.fnUP_down, func_up=buttons.fnUP_up, text='UP', font_size = font_size)
    buttonDOWN = button((w/2, 8*h/9), (w, h/3), (220, 220, 220), (255, 0, 0), fnDOWN, buttons.fnDOWN_down, buttons.fnDOWN_up, 'DOWN', font_size = font_size)



    crash = True
    while crash:
        screen.fill(bg)
        if menu == 1:
            button_list = [buttonSTART, buttonCONFIG]

        elif menu == 2:
            #pygame.draw.rect(screen, (255,0,0), pygame.Rect(3*w/4, h/2, w/3, h))
            #self.font = pygame.font.SysFont(font, 10)
            #self.txt_surf = self.font.render(msg, 1, clr)
            #screen.blit(self.txt_surf, self.position)
            #pygame.display.flip()
            # text_surface, rect = GAME_FONT.render("Hello World!", 1, clr)
            # screen.blit(text_surface, (40, 250))
            # or just `render_to` the target surface.
            #GAME_FONT.render_to(screen, (40, 350), "Hello World!", (0, 0, 0))
            font = pygame.font.SysFont(None, 24)
            img = font.render('CHEO XAC-PACK v1.3', True, (0,0,0))
            screen.blit(img, (w/2-100, 20))
            img = font.render('To access panel, connect a keyboard and pres ESC', True, (0,0,0))
            screen.blit(img, (20, 80))
            img = font.render('Project files at https://github.com/todocono/XAC-PACK', True, (0,0,0))
            screen.blit(img, (20, h-80))
            button_list = [] #buttonBACK
            mov = pygame.mouse.get_rel()
            if abs(mov[0]) > 5:
                if mov[0] > 0:
                    if not pressRight:
                        pressRight = True
                        buttons.fnRIGHT_down()
                    if pressLeft:
                        buttons.fnLEFT_up()
                        pressLeft = False
                else:
                    if not pressLeft:
                        pressLeft = True
                        buttons.fnLEFT_down()
                    if pressRight:
                        buttons.fnRIGHT_up()
                        pressRight = False
            if abs(mov[0]) == 0:
                if pressRight:
                    buttons.fnRIGHT_up()
                    pressRight = False
                if pressLeft:
                    buttons.fnLEFT_up()
                    pressLeft = False
            if abs(mov[1]) > 5:
                if mov[1] < 0:
                    if not pressUp:
                      pressUp = True
                      buttons.fnUP_down()
                    if pressDown:
                      buttons.fnDOWN_up()
                      pressDown = False
                else:
                    if not pressDown:
                        pressDown  = True
                        buttons.fnDOWN_down()
                    if pressUp:
                        buttons.fnUP_up()
                        pressUp = False
            if abs(mov[1]) == 0:
                if pressUp:
                    buttons.fnUP_up()
                    pressUp = False
                if pressDown:
                    buttons.fnDOWN_up()
                    pressDown = False

        if menu == 3:
          button_list = [buttonLEFT, buttonRIGHT, buttonUP, buttonDOWN] #, buttonBACK

        for b in button_list:
          b.draw(screen)


        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                crash = False
                pygame.quit()
                exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    crash = False
                    pygame.quit()
                    exit()

            elif event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                      buttons.fnCLICK_down()
                elif event.button == 3:
                      buttons.fnRCLICK_down()

                if event.button == 1:
                    pos = pygame.mouse.get_pos()
                    for b in button_list:
                        if b.rect.collidepoint(pos):
                            b.call_back()

            elif event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                      buttons.fnCLICK_up()
                elif event.button == 3:
                      buttons.fnRCLICK_up()

            #elif event.type == pygame.MOUSEMOTION and menu == 2:
           # if menu == 2:




        pygame.display.update()
        clock.tick(30)




'''button_list = [buttonLEFT, buttonRIGHT, buttonUP, buttonDOWN]
          mouse_movement = pygame.mouse.get_rel()
          mouse_diff_x = mouse_movement[0]
          mouse_diff_y = mouse_movement[1]

          if abs(mouse_diff_x) > 0 or abs(mouse_diff_y) > 0:
                if mouse_diff_x > 0:
                    buttons.fnRIGHT_down()
                else:
                    buttons.fnRIGHT_up()
                if mouse_diff_x < 0:
                    buttons.fnLEFT_down()
                else:
                    buttons.fnLEFT_up()

                if mouse_diff_y > 0:
                    buttons.fnUP_down()
                else:
                    buttons.fnUP_up()
                if mouse_diff_y < 0:
                    buttons.fnDOWN_down()
                else:
                    buttons.fnDOWN_up()

        for b in button_list:
          b.draw(screen)


        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                crash = False
                pygame.quit()
                quit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    crash = False
                    pygame.quit()
                    quit()
            elif event.type == pygame.MOUSEBUTTONDOWN:
                if event.button == 1:
                      buttons.fnCLICK_down()
                elif event.button == 3:
                      buttons.fnRCLICK_down()

                if event.button == 1:
                    pos = pygame.mouse.get_pos()
                    for b in button_list:
                        if b.rect.collidepoint(pos):
                            b.call_back()

            elif event.type == pygame.MOUSEBUTTONUP:
                if event.button == 1:
                      buttons.fnCLICK_up()
                elif event.button == 3:
                      buttons.fnRCLICK_up()'''
