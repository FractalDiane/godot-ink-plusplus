RSRC                    InkStoryCompiled            ²ûÎúÒ?|                                                  data    resource_local_to_scene    resource_name    script           local://InkStoryCompiled_6tmsm æ          InkStoryCompiled           hD  INKB  OffOn    KnifeKnowledge   
 SeenUnseen   
 Supporters   
 GlassState  none       
 GlassState  BedState  made_up        BedState 	 Inventory  none       
 GlassState  BedKnowledge    WindowKnowledge    x        knowledgeState     bedroomLightState  off        OffOn on_desk       
 Supporters 
 knifeState 	 under_bed       
 Supporters     	    OffOn    off         on        
 SeenUnseen    unseen         seen        
 GlassState   
 steam_gone         none         steamed         BedState    made_up         covers_shifted        
 covers_off         bloodstain_visible        	 Inventory    none         cane         knife        
 Supporters    with_joe         on_desk        	 under_bed         on_floor         on_bed         held         BedKnowledge    crumpled_duvet         neatly_made         hastily_remade         body_on_bed         murdered_in_bed         murdered_while_asleep         KnifeKnowledge    joe_wants_better_prints         prints_on_knife         joe_seen_prints_on_knife         joe_got_better_prints         WindowKnowledge    steam_on_glass         fingerprints_on_glass        ! fingerprints_on_glass_match_knife        	  move_to_supporter 
 item_state new_supporter       
 
 item_state
 Supporters
 LIST_ALL  
 
 item_state new_supporter  get  x       
 	 Inventory x  _S           murder_scene    pop  list      
   x list
 LIST_MIN  
  list x 
  x reached  x       
  knowledgeState x  between  x  y       
	  knowledgeState x  knowledgeState y   reach  statesToSet       
   x statesToSet
 pop   ¡  x           
  £  x
 reached           
   chain x
 LIST_ALL  
   statesGained chain chain
 LIST_MIN  x

 LIST_RANGE  
  knowledgeState statesGained 
  statesToSet
 reach
            
   statesToSet
 reach   	 murder_sceneª    operate_lamp  	    compare_prints 	 -> backto     see_prints_on_glass      
 seen_light%      6      top«            6        > The bedroom. This is where it happened. Now to look for clues.    bedroomLightState  seen       
 SeenUnseen                     
 seen_light                compare_prints   top	       
 The bed...         bedhub²      Æ        The bed was low to the ground  , N  but not so low something might not roll underneath. It was still neatly made.
   neatly_made        BedKnowledge 
 reach     Lift the bedcover            > I lifted back the bedcover. The duvet underneath was crumpled.
   crumpled_duvet        BedKnowledge 
 reach
  BedState  covers_shifted        BedState                     Remove the cover           ' Careful not to disturb anything beneath  , ;  I removed the cover entirely. The duvet below was rumpled.  Not the work of the maid  , N  who was conscientious to a point. Clearly this had been thrown on in a hurry.
   hastily_remade        BedKnowledge 
 reach
  BedState 
 covers_off        BedState      uncoverµ   ·   crumpled_duvet        BedKnowledge 
 reached           Pull back the duvet          
  / I pulled back the duvet. Beneath it was a sheet  ,   sticky with blood.
  BedState  bloodstain_visible        BedState  
   body_on_bed        BedKnowledge 
 reach F Either the body had been moved here before being dragged to the floor   - 1  or this is was where the murder had taken place.    duvetº   ¼  BedState 
 covers_off        BedState          Remake the bed            	 Carefully  , '  I pulled the bedsheets back into place  , $  trying to make it seem undisturbed.
  BedState  made_up        BedState             À  BedState  made_up        BedState      Test the bed           9 I pushed the bed with spread fingers. It creaked a little  , $  but not so much as to be obnoxious.                   Look under the bed           
 Lying down  ,   I peered under the bed  ,   but could make nothing out.   	 darkunderÂ           Something else?           2 I took a step back from the bed and looked around.  top              Ä  dobed
 TURNS_SINCE           bedhub       dobed°          Look under the bed         reachingÊ       5 I peered under the bed. Something glinted back at me.      Reach for it             # I fished with one arm under the bed  ,   but whatever it was  , I  it had been kicked far enough back that I couldn't get my fingers on it.  reaching                      Knock it with the cane            knock_with_cane              Í 	 Inventory  cane       	 Inventory        
  Stand up             I stood up once more  ,   and brushed my coat down.  top              Ð  reaching                   É	 	 darkunder bedroomLightState  on_floor       
 Supporters    bedroomLightState  on        OffOn            $ Use the cane to reach under the bed            % Positioning the cane above the carpet  , W  I gave the glinting thing a sharp tap. It slid out from the under the foot of the bed.
 
 knifeState  on_floor       
 Supporters 
 move_to_supporter        Stand up            	 Satisfied  ,   I stood up  , -  and saw I had knocked free a bloodied knife.  top       standupÖ         Look under the bed once more            Moving the cane aside  , !  I looked under the bed once more  , "  but there was nothing more there.  standup                   knock_with_caneÒ   Ô
  reaching reaching
 TURNS_SINCE          	 Inventory  cane       	 Inventory          Pick up the knife            Careful not to touch the handle  , $  I lifted the blade from the carpet.
   knife       	 Inventory 
 get           Ú 
 knifeState  on_floor       
 Supporters         Look at the knife           K The blood was dry enough. Dry enough to show up partial prints on the hilt!
   prints_on_knife        KnifeKnowledge 
 reach           Ý 	 Inventory  knife       	 Inventory         The desk...        	 deskstateà      ð       ; I turned my attention to the desk. A lamp sat in one corner  ,   a neat  , 	  empty in  - . tray in the other. There was nothing else out. + Leaning against the desk was a wooden cane.
  bedroomLightState  seen       
 SeenUnseen              Pick up the cane            
   cane       	 Inventory 
 get ) I picked up the wooden cane. It was heavy  ,   and unmarked.    pickup_caneá    ã 	 Inventory  cane       	 Inventory         Turn on the lamp            operate_lamp             æ  bedroomLightState  on        OffOn      Look at the in  -  tray          	   I regarded the in  -  tray  , H  but there was nothing to be seen. Either the victim's papers were taken  , 6  or his line of work had seriously dried up. Or the in  -  tray was all for show.                       Open a drawer            I tried                 a drawer at random             another drawer             a third drawer  .                 Locked             Also locked             Unsurprisingly  ,   locked as well  .   openè   ê  open               Something else?           + I took a step away from the desk once more.  top              î 	 deskstate         	 deskstate                      Swoosh the cane         	   I was still holding the cane  : 6  I gave it an experimental swoosh. It was heavy indeed  , 2  though not heavy enough to be used as a bludgeon. % But it might have been useful in self  - ? defence. Why hadn't the victim reached for it? Knocked it over?           ó 	 Inventory  cane       	 Inventory  	 deskstate
 TURNS_SINCE              The window...        window_optsô      
       k I went over to the window and peered out. A dismal view of the little brook that ran down beside the house.  compare_prints   window_opts        Look down at the brook              
 GlassState  steamed       
 GlassState              4 Through the steamed glass I couldn't see the brook.   see_prints_on_glass    window_opts                \ I watched the little stream rush past for a while. The house probably had damp but otherwise  ,   it told me nothing.    downy÷            Look at the glass             
 GlassState  steamed       
 GlassState                  downy                D The glass in the window was greasy. No one had cleaned it in a while  ,   inside or out.    greasyû         Look at the steam            4 A cold day outside. Natural my breath should steam.   see_prints_on_glass             ÿ
 
 GlassState  steamed       
 GlassState   see_prints_on_glass  downy  greasy         Breathe on the glass            * I breathed gently on the glass once more.      fingerprints_on_glass        WindowKnowledge 
 reached              The fingerprints reappeared.             
 
 GlassState  steamed       
 GlassState             
 GlassState 
 steam_gone       
 GlassState      Something else?            
  window_opts          fingerprints_on_glass        WindowKnowledge 
 reached 
 GlassState  steamed       
 GlassState               $ I looked away from the dreary glass.   
 GlassState  steamed       
 GlassState             
 
 GlassState 
 steam_gone       
 GlassState      The steam from my breath faded.              top                H I leant back from the glass. My breath had steamed up the pane a little.
 
 GlassState  steamed       
 GlassState               window_opts                      Leave the room            I'd seen enough. I     bedroomLightState  on        OffOn               switched off the lamp  ,   then               turned and left the room.  joe_in_hall                top          top     I flicked the light switch.    bedroomLightState  on        OffOn                The bulb fell dark.
  bedroomLightState  off        OffOn  
  bedroomLightState  on        OffOn                 bedroomLightState  on_floor       
 Supporters                 &  A little light spilled under the bed.                   bedroomLightState  on_desk       
 Supporters                 -  The light gleamed on the polished tabletop.             
  bedroomLightState  off        OffOn  
  bedroomLightState  on        OffOn             / Compare the prints on the knife and the window             * Holding the bloodied knife near the window  , -  I breathed to bring out the prints once more  , #  and compared them as best I could.  Hardly scientific  ,   but they seemed very similar   -   very similiar indeed.
  ! fingerprints_on_glass_match_knife        WindowKnowledge 
 reach  backto                 prints_on_knife        KnifeKnowledge fingerprints_on_glass        WindowKnowledge  ! fingerprints_on_glass_match_knife        WindowKnowledge 
 between
   fingerprints_on_glass        WindowKnowledge 
 reach               " But I could see a few fingerprints  , 4  as though someone hadpressed their palm against it.            * The fingerprints were quite clear and well  -  formed.   They faded as I watched.
 
 GlassState 
 steam_gone       
 GlassState               Turn on lamp              operate_lamp             '  bedroomLightState  on        OffOn       Move the light to the bed           
  bedroomLightState  on_bed       
 Supporters 
 move_to_supporter | I moved the light over to the bloodstain and peered closely at it. It had soaked deeply into the fibres of the cotton sheet. E There was no doubt about it. This was where the blow had been struck.
   murdered_in_bed        BedKnowledge 
 reach           *  bedroomLightState  on_bed       
 Supporters   BedState  bloodstain_visible        BedState         !  Move the light back to the desk           
  bedroomLightState  on_desk       
 Supporters 
 move_to_supporter " I moved the light back to the desk  , .  setting it down where it had originally been.           .  bedroomLightState  on_desk       
 Supporters  0  floorit
 TURNS_SINCE                Move the light to the floor           
  bedroomLightState  on_floor       
 Supporters 
 move_to_supporter 3 I picked the light up and set it down on the floor.    floorit2   4  bedroomLightState  on_floor       
 Supporters  	 darkunder   top    joe_in_hall8      found9      Q     doneS      	  h My police contact, Joe, was waiting in the hall. 'So?' he demanded. 'Did you find anything interesting?'     'Nothing.'             He shrugged. 'Shame.'  done              ;  found            'I found the murder weapon.'           q 'Good going!' Joe replied with a grin. 'We thought the murderer had gotten rid of it. I'll bag that for you now.'
 
 knifeState  with_joe       
 Supporters 
 move_to_supporter           > 	 Inventory  knife       	 Inventory        'There are prints on the blade   .'  ,  ' I told him.            He regarded them carefully. B 'Hrm. Not very complete. It'll be hard to get a match from these.'
   joe_seen_prints_on_knife        KnifeKnowledge 
 reach           A   prints_on_knife        KnifeKnowledge 
 reachedC 
 knifeState  with_joe       
 Supporters    ) 'They match a set of prints on the window  ,   too.'           % 'Anyone could have touched the window  , 9 ' Joe replied thoughtfully. 'But if they're more complete  , )  they should help us get a decent match!'
   joe_wants_better_prints        KnifeKnowledge 
 reach           F   joe_seen_prints_on_knife        KnifeKnowledge! fingerprints_on_glass_match_knife        WindowKnowledge 
 reached  , 'The body was moved to the bed at some point   .'  , 1 ' I told him. 'And then moved back to the floor.'            'Why?'    'I don't know.'             Joe nods. 'All right.'              * 'Perhaps to get something from the floor?'           * 'You wouldn't move a whole body for that.'               'Perhaps he was killed in bed.'           $ 'It's just speculation at this point  ,  ' Joe remarks.                       I   body_on_bed        BedKnowledge   murdered_in_bed        BedKnowledge 
 between   'The victim was murdered in bed  , +  and then the body was moved to the floor.'            'Why?'    'I don't know.'             Joe nods. 'All right  ,   then.'              , 'Perhaps the murderer wanted to mislead us.'         L     
  	 'How so?'   - 'They wanted us to think the victim was awake   .'  , ?  I replied thoughtfully. 'That they were meeting their attacker  , +  rather than being stabbed in their sleep.'                          8 'They wanted us to think there was some kind of struggle   .'  , D ' I replied. 'That the victim wasn't simply stabbed in their sleep.'                         'But if they were killed in bed  , *  that's most likely what happened. Stabbed  ,   while sleeping.'
   murdered_while_asleep        BedKnowledge 
 reach              3 'Perhaps the murderer hoped to clean up the scene.'           ) 'But they were disturbed? It's possible.'                       K   murdered_in_bed        BedKnowledge 
 reached    'That's it.'            'All right. It's a start  ,  ' Joe replied.  done              O  found          found     U   joe_wants_better_prints        KnifeKnowledge   joe_got_better_prints        KnifeKnowledge 
 between           
   joe_got_better_prints        KnifeKnowledge 
 reach -  'I'll get those prints from the window now.'W   joe_seen_prints_on_knife        KnifeKnowledge 
 reached            '  'I'll run those prints as best I can.'              'Not much to go on.'  END   	  _S pop get move_to_supporter reached between reach murder_scene joe_in_hall      RSRC