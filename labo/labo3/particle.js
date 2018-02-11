class Util {
    static extends (object, defaults) {
        if (!Util.isObject(object)) object = {};
        if (!Util.isObject(defaults)) defaults = {};
        
        for (let k in defaults) {
            object[k] = object[k] || defaults[k]
        }
        return object
    }

    static isObject (target) {
        return target !== null && typeof target === 'object'
    }

    static isFunction (target) {
        return typeof(obj) === 'function'
    }
}

class Particle {
    constructor (options) {
        this.options = {
            targetId: 'target',
            count: 300,
            radius: 2,
            speed: 0.05,
            color: '#FFFFFF',
            threshold: 60
        }

        Util.extends(this.options, options)
        
        const wrapper = document.getElementById(this.options.targetId)
        if (!wrapper) console.err(`There is no element of id ${targetId}`)
        this.canvas = document.createElement('canvas')
        this.canvas.width = wrapper.offsetWidth
        this.canvas.height = wrapper.offsetHeight
        this.canvas.style.width = '100%'
        this.canvas.style.height = '100%'
        wrapper.appendChild(this.canvas)

        this.context = this.canvas.getContext('2d')
        this.createParticles()

        this.lastUpdate = Date.now()
        this.loop()
    }

    createParticles() {
        this.particles = [];
        for (let i = 0; i < this.options.count; ++i) {
            this.particles.push({
                x: Math.random(),
                y: Math.random(),
                radius: this.options.radius + (Math.random() * 2 - 1),
                speed: this.options.speed * (Math.random() * 2),
                direction: Math.round(Math.random() * 360)
            })
        }
    }
    
    loop () {
        const now = Date.now()
        this.update(now - this.lastUpdate)
        this.lastUpdate = now
        this.draw()
        return requestAnimationFrame(this.loop.bind(this))
    }

    update (deltaTime) {
        for (let i = 0; i < this.particles.length; i++) {
            const radians = (Math.PI / 180) * (this.particles[i].direction - 90)
            this.particles[i].x += deltaTime * Math.cos(radians) * this.particles[i].speed / this.canvas.width
            this.particles[i].y += deltaTime * Math.sin(radians) * this.particles[i].speed / this.canvas.width

            this.particles[i].x >= 1 && (this.particles[i].x -= 1)
            this.particles[i].x < 0 && (this.particles[i].x += 1)
            this.particles[i].y >= 1 && (this.particles[i].y -= 1)
            this.particles[i].y < 0 && (this.particles[i].y += 1)
        }
    }

    draw () {
        this.context.clearRect(0, 0, this.canvas.width, this.canvas.height)
        this.context.fillStyle = this.options.color
        this.context.strokeStyle = this.options.color

        for (let i = 0; i < this.particles.length; ++i) {
            this.context.beginPath();

            this.context.arc(this.particles[i].x * this.canvas.width, this.particles[i].y * this.canvas.height, this.particles[i].radius, 0, 2 * Math.PI);
            
            this.context.closePath()
            this.context.fill()

            for (let j = i + 1; j < this.particles.length; ++j) {
                this.link(this.particles[i], this.particles[j])
            }
        }

        // this.context.font = '40px Nunito'
        // this.context.fillText('Alexandre', this.canvas.width / 2 - this.context.measureText('Alexandre').width / 2, this.canvas.height / 2 - 30)
        // this.context.font = '50px Rammetto One'
        // this.context.lineWidth = 1
        // this.context.fillStyle = '#353535'
        // this.context.fillText('Frigon', this.canvas.width / 2 - this.context.measureText('Frigon').width / 2, this.canvas.height / 2 + 30)
        // this.context.strokeText('Frigon', this.canvas.width / 2 - this.context.measureText('Frigon').width / 2, this.canvas.height / 2 + 30)
    }

    link (p1, p2) {
        const distance = Math.sqrt(Math.pow(p2.x * this.canvas.width - p1.x * this.canvas.width, 2) + Math.pow(p2.y * this.canvas.height - p1.y * this.canvas.height, 2))
        const thresholdOffset = 20;
        const farThreshold = this.options.threshold + thresholdOffset
        if (distance < farThreshold) {
            this.context.globalAlpha = 1 - (distance / farThreshold)
            this.context.beginPath()
            this.context.lineWidth = 1
            this.context.moveTo(p1.x * this.canvas.width, p1.y * this.canvas.height)
            this.context.lineTo(p2.x * this.canvas.width, p2.y * this.canvas.height)
            this.context.stroke()
            this.context.closePath()
            this.context.globalAlpha = 1
        }
    }
}

new Particle({ targetId: 'target' })