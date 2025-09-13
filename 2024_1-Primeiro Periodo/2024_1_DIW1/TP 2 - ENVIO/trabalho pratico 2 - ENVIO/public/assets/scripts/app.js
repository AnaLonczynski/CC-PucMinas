
fetch('https://api.github.com/users/matheusscxr')
    .then(res => res.json())
    .then(data => {
        console.log(data);
        // atualizando o HTML
        document.getElementById('perfil_imagem').src = data.avatar_url;
        document.getElementById('perfil_nome').innerHTML = data.name;
        document.getElementById('perfil_bio').innerHTML = data.bio;
        document.getElementById('perfil_url').href = data.html_url;
        document.getElementById('perfil_loc').innerHTML += data.location;
        document.getElementById('perfil_seguidores').innerHTML += data.followers;  
    })
    .catch(error => console.error('Erro ao buscar dados:', error));


//feth para buscar dados do respositórios
 fetch('https://api.github.com/users/matheusscxr/repos')
    .then(res => res.json())
    .then(data => {
        console.log(data);
        // atualizando o HTML para incluir os repositórios
        var num_cards = '(' + data.length + ')';
        document.getElementById('perfil_cards_num').innerHTML += num_cards;
        var cards = '';
        for (let i = 0; i < data.length; i++) {
          var repo = data[i];
          cards += `
            <div class="col-md-6 col-lg-3 col-sm-12">
            <a href="repo.html?id=${repo.id}" target="_blank" class="text-decoration-none">
                <div class="card border-dark mb-3" style="max-width: 18rem; height: 26rem;">
                  <div class="card-header border-dark bg-dark fw-bolder text-white text-center">${repo.full_name}</div>
                  <div class="card-body text-dark">
                    <h5 class="card-title fw-bold">${repo.name}</h5>
                    <p class="card-text">${repo.description || 'Sem descrição'}</p>
                  </div>
                  <div class="card-footer bg-transparent border-dark text-center">
                    <i class="fa-solid fa-star mr-2">${repo.stargazers_count}</i>
                    <span class="m-5">
                      <i class="fa-solid fa-user m-1">${repo.forks_count}</i>
                    </span>
                  </div>
                </div>
              </a>
            </div>
          `;
        }

        document.getElementById('perfil_cards').innerHTML = cards;

    })
    .catch(error => console.error('Erro ao buscar dados:', error));


const urlJSONcarrossel = '/carrossel';

fetch(urlJSONcarrossel)
  .then(response => response.json()) // convertendo a resposta para JSON
  .then(data => {
    console.log(data);
    var slides = '';
    for (let i = 0; i < data.length; i++ )
      {
        let json = data[i];
        slides += `
          <div class="carousel-item ${i === 0 ? 'active' : ''}">
            <img src="${json.img}" class="d-block w-100" alt="${json.alt}">
             <div class="card-img-overlay">
               <h5 class="card-title text-light p-4 fw-bolder">${json.desc}</h5>
              </div>
          </div>
        `;
      }

    document.getElementById('carrossel_slides').innerHTML = slides;
  })



// Por motivos de privacidade e segurança, a API do github não disponibiliza o email
// nem as redes sociais, a não ser que tenha uma chave de acesso, e, por isso
// não coloquei a chave nesse projeto. Dessa forma, essas informações serão "puxadas"
// no JSON local.

const urlPerfilJSON = '/perfil';

fetch(urlPerfilJSON)
  .then(response => response.json())
  .then(data => {
    const perfil = data[0];
    // Atualizando o email
    const emailElement = document.getElementById('perfil_email');
    if (emailElement) {
      emailElement.querySelector('a').href = `mailto:${perfil.email}`;
      emailElement.querySelector('a').textContent = perfil.email;
    }

    // Atualizando o Twitter
    const twitterElement = document.getElementById('perfil_twitter').querySelector('a');
    if (twitterElement) {
      twitterElement.href = perfil.twitter;
    }

    // Atualizando o Instagram
    const instaElement = document.getElementById('perfil_insta').querySelector('a');
    if (instaElement) {
      instaElement.href = perfil.insta;
    }
  })
  .catch(error => console.error('Erro ao carregar os dados do perfil:', error));











const urlJSONColegas = '/colegas';

function carregarJSONColegas() {
  fetch(urlJSONColegas)
    .then(response => response.json())
    .then(data => {
      console.log(data);
      var colegas_card = '';
      for (let i = 0; i < data.length; i++ )
        {
          let json = data[i];
          colegas_card += `
            <div class="col-lg-2 col-md-6">
              <div class="card mb-3" style="max-width: 200px; max-height: 300px;">
                <img id="colega_${json.id}" src="${json.img}" class="card-img-top" alt="${json.alt}" style="max-width: 200px; max-height: 200px;">
                <div class="card-body">
                  <h5 id="colega_${json.id}" class="card-title">${json.nome}</h5>
                </div>
              </div>
            </div>
          `;
        }
      
      document.getElementById('colegas_cards').innerHTML = colegas_card;
    })
}

document.addEventListener('DOMContentLoaded', function() {
  carregarJSONColegas();
});