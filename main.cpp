#include <iostream>
#include <cstdlib>
#include <time.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
using namespace std;

//_____________________________________________________
int leader_P(int *r,int count);
int snake_P(int *r,int *count,int *x, int *y);
int  player1(int *count ,int *r ,int *x , int *y);
void  dice(int r);
void dice2(int r);

//________________________________________________________
int width=800;
int height=700;
//_________________________________________________________

int main ()
{
	al_init();
	al_init_image_addon();
	ALLEGRO_DISPLAY *display;
	al_install_audio();
	al_init_acodec_addon();
	display = al_create_display(width,height);

	ALLEGRO_BITMAP *background=al_load_bitmap("image2.png");
	ALLEGRO_BITMAP *player1=al_load_bitmap("red.png");
	ALLEGRO_BITMAP *lucky=al_load_bitmap("LUCKY.png");
	ALLEGRO_BITMAP *welcome=al_load_bitmap("welcome.png");
    ALLEGRO_BITMAP *winner=al_load_bitmap("winner.png");
    ALLEGRO_BITMAP *player2=al_load_bitmap("blue.png");

    al_reserve_samples(1);
// for music
    ALLEGRO_SAMPLE *sample = al_load_sample("musicc.wav");
    al_play_sample(sample, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, 0);
// __________________________________

	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(welcome,0,0,0);
        al_flip_display();
        al_rest(5);
	al_clear_to_color(al_map_rgb(0,0,0));
	al_draw_bitmap(background,100,0,0);
	al_draw_bitmap(lucky,0,100,0);
        al_flip_display();


   ALLEGRO_EVENT_QUEUE *queue=al_create_event_queue();
   ALLEGRO_KEYBOARD_STATE keystate;
   al_install_keyboard();


    int x=110, y=655, r=0 ,count=1 ,r1=0 ,count1=1 ,x2=110, y2=655,rand_num1,rand_num2;//defines coordinates of board 

    al_register_event_source(queue, al_get_keyboard_event_source());
    al_register_event_source(queue, al_get_display_event_source(display));
	bool flage= false ;

while (!flage)
{
	al_clear_to_color(al_map_rgb(50,0,0));
	al_draw_bitmap(background,100,0,0);

	ALLEGRO_EVENT events;
	al_wait_for_event(queue, &events);
	if (events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (events.keyboard.keycode)
		{
			case ALLEGRO_KEY_SPACE :
				srand(time(0));
				r=(rand()%6)+1;
			    rand_num1=r;
				dice2(rand_num1);
//				cout<<"player 1 =>"<<r<<endl;
			 	break;
			case ALLEGRO_KEY_ESCAPE:
				flage = true;
				exit;
			default :
				r=0;
				     break;
		}
// FIRST PLAYER  MOVES

	if (count+r <= 100)

	{
		leader_P(&r,count);//this function check for leader or not .
		snake_P(&r,&count,&x,&y);//this will check either he is on snake or not .

			for (int i=1 ; i<=r ; i++)
			{
			
				if ((count<10) || (count >=20 && count<30) ||(count >=41 && count<50)||(count >=61 && count < 70 )||(count >=81 && count < 90))
					{
						x +=70;//for going forward 
					}
				if ((count > 10 && count <21) || (count >=31 && count <40)||(count >=51 && count <60)||(count >=71 && count <80 )|| (count >=91 && count<=100))
					{
						x -=70;//for going backword
					}
                if (count ==10 ||count==20||count==30 ||count==40 ||count==50 ||count==60 ||count==70 ||count==80 ||count==90)
                   	{
                    	y =y-70;
					}
			//this block show display
				al_clear_to_color(al_map_rgb(50,0,0));
				al_draw_bitmap(lucky,0,100,0);
		       	        al_draw_bitmap(background,100,0,0);
		       	        dice (rand_num1);
		         	al_draw_bitmap(player1,x,y,0);
				al_draw_bitmap(player2,x2,y2,0);
		                al_flip_display();
				al_rest(0.2);
				count +=1;
				

			}//for loop end
	}
		if(count==100)
			{
			al_clear_to_color(al_map_rgb(0,0,0));
			al_draw_bitmap(winner,0,0,0);
		        al_flip_display();
                        al_rest(10);
			}
}
//_______________________________________SECOND PLAYER MOVES ____________________________

	al_wait_for_event(queue, &events);
	if (events.type == ALLEGRO_EVENT_KEY_DOWN)
	{
		switch (events.keyboard.keycode)
		{

			case ALLEGRO_KEY_SPACE :
				srand(time(0));
				r1=(rand()%6)+1;
				rand_num2=r1;
				dice2(rand_num2);
			 	break;
			case ALLEGRO_KEY_ESCAPE:
				flage = true;
				exit;
			default :
				r1=0;
				     break;
		}


	if (count1+r1 <= 100)
	{
        
		leader_P(&r1,count1);
		snake_P(&r1,&count1,&x2,&y2);

			for (int i=1 ; i<=r1 ; i++)
            {
				
				if ((count1<10) || (count1 >=20 && count1<30) ||(count1 >=41 && count1<50)||(count1 >=61 && count1 < 70 )||(count1 >=81 && count1 < 90))
					{
						x2 +=70;
					}
				if ((count1 > 10 && count1 <21) || (count1 >=31 && count1 <40)||(count1 >=51 && count1 <60)||(count1 >=71 && count1 <80 )|| (count1 >=91 && count1<=100))
					{
						x2 -=70;
					}
                if (count1 ==10 ||count1==20||count1==30 ||count1==40 ||count1==50 ||count1==60 ||count1==70 ||count1==80 ||count1==90)
                   	{
                    	y2 =y2-70;
					}
					
				
				 al_clear_to_color(al_map_rgb(50,0,0));
				al_draw_bitmap(lucky,0,100,0);
		       	al_draw_bitmap(background,100,0,0);
		       	dice2(rand_num2);
		       	al_draw_bitmap(player1,x,y,0);
				al_draw_bitmap(player2,x2,y2,0);
		        al_flip_display();

				al_rest(0.2);
				count1 +=1;
			
			}//for loop end
	} 
		if(count1 == 100)
			{
				al_clear_to_color(al_map_rgb(0,0,0));
				al_draw_bitmap(winner,0,0,0);
		        	al_flip_display();
                		al_rest(10);
			}
	}
//____________________________________________________________________________________________________________
}

   al_destroy_display(display);
   al_destroy_bitmap(player1);
   al_destroy_bitmap(player2);
   al_destroy_bitmap(winner);
   al_destroy_bitmap(welcome);
   al_destroy_bitmap(lucky);
   al_destroy_bitmap(background);
  al_destroy_sample(sample);
   al_uninstall_keyboard();
}
/*_______________________________________
MAIN COMPLETE
*///_____________________________________
int leader_P(int *r,int count)
{

			  	 if (*r==1 and count==1)
			  	  {
			  		*r +=36;
				  }
				if (*r+count==4)
				{
				  *r+=10;
				}
				if (*r+count == 10 )
				{
					*r +=21;
				}
				if (*r+count == 28)
				{
					*r +=56;
				}
				if (*r+count == 51)
				{
						*r +=16;
				}
				if (*r+count == 71)
				{
					*r +=20;
				}
				if (*r+count == 80)
				{
					*r +=20;
				}
				if (*r+count ==21)
				{
					*r +=21;
				}
	return *r;

}
/*
_______________________________________________
*/
int snake_P(int *r,int *count,int *x, int *y)
{
	 if (*r+*count ==17)
			 	{
			 	 *count =1 ;
			 	  *r=6;
			 	 *x=110;
				 *y=655;
				}
			else if (*r+*count ==62)
			 	{
			 	 *count =1 ;
			 	  *r=18;
			 	 *x=110;
				 *y=655;
				}
			else if (*r+*count ==64)
			 	{
			 	 *count =1 ;
			 	  *r=59;
			 	 *x=110;
				 *y=655;
				}
			else if (*r+*count ==54)
			 	{
			 	 *count =1 ;
			 	  *r=33;
			 	 *x=110;
				 *y=655;
				}
			else if (*r+*count ==86)
			 	{
			 	 *count =1 ;
			 	  *r=23;
			 	 *x=110;
				 *y=655;
				}
			else if (*r+*count ==93)
			 	{
			 	 *count =1 ;
			 	  *r=72;
			 	 *x=110;
				 *y=655;
				}
			else if (*r+*count ==95)
			 	{
			 	 *count =1 ;
			 	  *r=74;
			 	 *x=110;
				 *y=655;
				}
			else if (*r+*count ==98)
			 	{
			 	  *count =1 ;
			 	  *r=78;
			 	  *x=110;
				  *y=655;
				}
return *count , *r , *x , *y;
}
/*_______________________..________________________
DICE FOR FIRST PLAYER
*/

void dice(int r )
{
	    al_init();
	    al_init_image_addon();
	switch(r)
	{

	case 1 :
			{
		        ALLEGRO_BITMAP *dice1=al_load_bitmap("dbl1.png");
		        al_draw_bitmap(dice1,0,0,0);
		        break;
			}
	case 2 :
			{
			ALLEGRO_BITMAP *dice2=al_load_bitmap("dbl2.png");
		        al_draw_bitmap(dice2,0,0,0);
		        break;
			}

	case 3 :
			{
		        ALLEGRO_BITMAP *dice3=al_load_bitmap("dbl3.png");
		        al_draw_bitmap(dice3,0,0,0);
		        break;
			}


	case 4 :
			{
		 	ALLEGRO_BITMAP *dice4=al_load_bitmap("dbl4.png");
		        al_draw_bitmap(dice4,0,0,0);
		        break;
			}

	case 5 :
			{

	        	ALLEGRO_BITMAP *dice5=al_load_bitmap("dbl5.png");
		        al_draw_bitmap(dice5,0,0,0);
		        break;

			}

	default :
			{

		        ALLEGRO_BITMAP *dice6=al_load_bitmap("dbl6.png");
		        al_draw_bitmap(dice6,0,0,0);
		    	break;
			}
}
}

/*__________________________________________________________________
DICE2 FOR SECOND PLAYER
*/
void dice2(int r )
{
	    al_init();
		al_init_image_addon();
	switch(r)
	{

	case 1 :
			{
		        ALLEGRO_BITMAP *dice1=al_load_bitmap("dgl1.png");
		        al_draw_bitmap(dice1,0,0,0);
		        break;
			}
	case 2 :
			{
			ALLEGRO_BITMAP *dice2=al_load_bitmap("dgl2.png");
		        al_draw_bitmap(dice2,0,0,0);
		        break;
			}

	case 3 :
			{
		        ALLEGRO_BITMAP *dice3=al_load_bitmap("dgl3.png");
		        al_draw_bitmap(dice3,0,0,0);
		        break;
			}


	case 4 :
			{
		 	ALLEGRO_BITMAP *dice4=al_load_bitmap("dgl4.png");
		        al_draw_bitmap(dice4,0,0,0);
		        break;
			}

	case 5 :
			{
	        	ALLEGRO_BITMAP *dice5=al_load_bitmap("dgl5.png");
		        al_draw_bitmap(dice5,0,0,0);
		        break;
			}

	default :
			{
		        ALLEGRO_BITMAP *dice6=al_load_bitmap("dgl6.png");
		        al_draw_bitmap(dice6,0,0,0);
		    	break;
			}
}
}








