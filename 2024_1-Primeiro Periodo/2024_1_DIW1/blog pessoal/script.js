const repos = document.getElementById('repositorios')
const conteudos = '/conteudos'
const colegas = '/colegas'


async function telaRepo(idRepo){
  console.log("opening")
  window.open("repo.html", "_self")
  console.log("opened")
  fetch('https://api.github.com/users/AnaLonczynski/repos')
  .then(async res =>{
    if (!res.ok){
      throw new Error(res.status)
    }

    var data = await res.json()

    data.forEach(item => {
      if(item.id == idRepo){

        let nome = document.getElementById('nomeRepo')
        nome.innerHTML = item.name

        let descricao = document.getElementById('descRepo')
        descricao.innerHTML = item.description

        let criacao = document.getElementById('criacaoRepo')
        criacao.innerHTML = Intl.DateTimeFormat('pt-BR').format(new Date(item.created_at))

        let linguagem = document.getElementById('lingRepo')
        linguagem.innerHTML = item.language

        let link = document.getElementById('linkRepo')
        link.href = item.html_url
        link.innerHTML = item.html_url

        let botao = document.getElementById('botaoRepo')
        botao.href = item.html_url
        console.log(modified)
      }

    })

  })
}
function Secao1(){
  fetch('https://api.github.com/users/AnaLonczynski')
  .then(async res =>{
    if (!res.ok){
      throw new Error(res.status)
    }

    var data = await res.json()

    let pfp = document.getElementById('profilephoto')
    pfp.src = data.avatar_url

    let nome = document.getElementById('nome')
    nome.innerHTML = data.name

    let bio = document.getElementById('bio')
    bio.innerHTML = data.bio

    let github = document.getElementById('linkgithub')
    github.href = data.html_url

  })
}
console.log("secao 1")
function Secao2(){
  fetch('https://api.github.com/users/apolobagattini/repos')
  .then(async res =>{
    if (!res.ok){
      throw new Error(res.status)
    }

    var data = await res.json()

    data.map(item=>{
      let repo = document.createElement('div')


      repo.innerHTML = `
              <div class="col">
                <div class="card">
                  <div class="card-body">
                    <a class="card-title" href="javascript:telaRepo(${item.id})">${item.name}</a>
                    <p class="card-text">${item.description}</p>
                  </div>
                </div>
      `
      repos.appendChild(repo)
    })
  }).catch(e => console.log(e))
}
console.log("secao 2")

function Secao3(){
  fetch(conteudos)
    .then(response => response.json())
    .then(itens => {
      const itensContainer = document.getElementById('carousel');

      itens.forEach(item => {
        const itemDiv = document.createElement('div');

        itemDiv.classList.add('carousel-item');
        if(item.id == 1){
          itemDiv.classList.add('active')
        }
        itemDiv.innerHTML = `
                        <a href=${item.link} target="_blank"><img src="${item.imagem}" class="d-block w-100 img-fluid" alt="Imagem 1"></a>
                        <div class="carousel-caption d-none d-md-block">
                          <h5 class="bg-dark">${item.titulo}</h5>
                          <p class="bg-dark">${item.descricao}</p>
                        </div>
        `;
        itensContainer.appendChild(itemDiv);

      });
    });
}
console.log("secao 3")

function Secao4(){
  fetch(colegas)
    .then(response => response.json())
    .then(itens => {
      const itensContainer = document.getElementById('colegas');

      itens.forEach(item => {
        const itemDiv = document.createElement('div');

        itemDiv.classList.add('item');
          itemDiv.innerHTML = `
                      <div class="col d-flex justify-content-center colega">
                        <a href=${item.github} target="_blank"><img src="${item.foto}" alt="Colega n°${item.id}" class="img-thumbnail img-fluid"></a>
                      </div>
          `;
          itensContainer.appendChild(itemDiv);
      });
      itens.forEach(item => {
        const itemDiv = document.createElement('div');

        itemDiv.classList.add('item');
          itemDiv.innerHTML = `
                      <div class="col d-flex justify-content-center colega-nome">${item.nome}</div>
          `;
          itensContainer.appendChild(itemDiv);
      });
    });
}
console.log("secao 4")


Secao1()
Secao2()
Secao3()
Secao4()
console.log("fim")

