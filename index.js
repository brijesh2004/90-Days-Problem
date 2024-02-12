
const GetVideo = ()=> {
    const iframe_id = document.getElementById('iframe_id');
    const input  = document.getElementById("inputId").value;
    let url = input.slice(23,input.length);
    url = `https://www.youtube.com/embed/${url}`;
    console.log(url);
    iframe_id.src=url;
}