import openai

# Sisesta oma API võti
openai.api_key = "sinu-api-võti"

def generate_text(prompt):
    response = openai.ChatCompletion.create(
        model="gpt-4",  # Kui gpt-4 pole saadaval, proovi "gpt-3.5-turbo"
        messages=[
            {"role": "user", "content": prompt}
        ],
        max_tokens=150,
        temperature=0.7  # Määrab loovuse taseme
    )
    return response.choices[0].message.content.strip()

# Kasutaja sisestus
teema = input("Sisesta teema või küsimus: ")
vastus = generate_text(teema)
print(f"AI vastus: {vastus}")
