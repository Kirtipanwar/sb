import discord
import os
import requests
import json
import random
from replit import db
from keep_alive import keep_alive



client = discord.Client()

sad_words = ["sad" , "depressed" , "sed" , "depress" , "unhappy" , "angry" , "ugh" , "gawd" , "dam" , "miserable" , "help" , "unfair" , "mad", "confused","love","high","roast","fuck you","f","fu", "fo","duhhhh","no way","hate"]

starter_encouragements = ["pip loves you <3" , "When I am sad, I stop being sad and be awesome instead", "dababy got u" , "Reality is often disappointing", "Sometimes I’ll start a sentence and I don’t even know where it’s going. I just hope I find it along the way.", "Would I rather be feared or loved? Easy. Both. I want people to be afraid of how much they love me.","Identity theft is not a joke, Jim! Millions of families suffer every year." , "I am running away from my responsibilities. And it feels good.", "If I were buying my coffin, from replit import dbI would get one with thicker walls so you couldn’t hear the other dead people.","And I knew exactly what to do. But in a much more real sense, I had no idea what to do.","There’s a lot of beauty in ordinary things. Isn’t that kind of the point?","It’s just, eventually, we’re all gonna move on. It’s called growing up.","The future is scary, but you can’t just run back to the past because it’s familiar. Yes, it’s tempting, but it’s a mistake.","Because sometimes even if you know how something’s gonna end, that doesn’t mean you can’t enjoy the ride.","Oh my god, look at you cowards. So afraid of any kind of change. So terrified of anything new. So, so desperate to cling to anything comfortable and familiar.","The three-day rule is a childish, manipulative mind game. But yeah, you wait three days.","So really the biggest mistake would be not to make that mistake, because then you’ll go your whole life not knowing if something was a mistake or not.","The best I can give you is a fake smile and dead eyes.","I realized that I’m searching, searching for what I really want in life. And you know what? I have absolutely no idea what that is.","I’d take a bullet for you. Not in the head. But like in the leg or something.","We are best friends. Always remember that if you fall , I will pick you up… after I finish laughing.","You don’t have to be crazy to be my friend. I’ll train you.","This is all a moo point.","You can’t just give up. Is that what a dinosaur would do?","I’m not so good with the advice. Can I interest you in a sarcastic comment?","You are a good person. Please don't be sad! Pip is there for you!!"]

if "responding" not in db.keys():
  db["responding"] = True


def get_quote():
  response = requests.get("https://zenquotes.io/api/random")

  json_data = json.loads(response.text)
  quote = json_data[0]['q'] + " - " + json_data[0]['a']
  return (quote)

def update_encouragements(encouraging_message):
  if "encouragements" in db.keys():
    encouragements = db["encouragements"]
    encouragements.append(encouraging_message)
    db["encouragements"] = encouragements
  else :
    db["encouragements"] = [encouraging_message]

def delete_encouragements(index):
  encouragements = db["encouragements"]
  if len(encouragements) > index:
    del encouragements[index]
    db["encouragements"] = encouragements

@client.event
async def on_ready():
  print("oh no Freak has logged in as {0.user}".format(client))

@client.event
async def on_message(message):
  if message.author == client.user:
    return
  
  msg = message.content

  if msg.startswith('pip hello'):
    quote = get_quote()
    await message.channel.send('Hello! I hope you have a great day ahead! Always remember ~~ ' + quote)

  if msg.startswith('pip serotonin'):
    quote = get_quote()
    await message.channel.send('Here is your daily crumb of serotonin:   ' + quote)
  
  if msg.startswith('pip inspire'):
    quote = get_quote()
    await message.channel.send(quote)
  
  if db["responding"]:
    options = starter_encouragements
    if "encouragements" in db.keys():
      options = options + db["encouragements"]    
    
    if any(word in msg for word in sad_words):
      await message.channel.send(random.choice(options))

  if message.content.startswith('chaos'):
    await message.channel.send('chaos is a dumbo cmon we all know that huh')
  
  if msg.startswith("pip new"):
    encouraging_message = msg.split("pip new ",1)[1]
    update_encouragements(encouraging_message)
    await message.channel.send("Thank you for updating the serotonin module!")
  
  if msg.startswith("pip delete"):
    encouragements = []
    if "encouragements" in db.keys():
      index = int(msg.split("pip delete",1)[1])
      delete_encouragements(index)
      encouragements= db["encouragements"]
    await message.channel.send(encouragements)

  if msg.startswith("pip list"):
    encouragements = []
    if "encouragements" in db.keys():
      encouragements = db["encouragements"]
    await message.channel.send(encouragements)

  if msg.startswith("pip status"):
    value = msg.split("pip status ",1)[1]

    if value.lower() == "true":
      db["pip status"] = True
      await message.channel.send("Cool, pip is turned on!")
    else:
      db["pip status"] = False
      await message.channel.send("Cool, pip is turned off!")

keep_alive()
client.run(os.getenv('key'))
